#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class AllOne {
    // Bucket represents keys with the same count
    class Bucket {
    public:
        int count;
        unordered_set<string> keys; // unordered_set instead of LinkedHashSet, order usually doesn't matter for "any"
        Bucket *prev, *next;
        Bucket(int count) {
            this->count = count;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    unordered_map<string, int> keyCount; // Maps key -> its count
    unordered_map<int, Bucket*> countBucket; // Maps count -> bucket of keys
    Bucket *head, *tail; // Dummy head and tail of doubly linked list
    
public:
    AllOne() {
        head = new Bucket(-1); // Dummy head
        tail = new Bucket(-1); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    // Helper method to add a bucket after the given bucket
    void addBucketAfter(Bucket* newBucket, Bucket* prevBucket) {
        newBucket->prev = prevBucket;
        newBucket->next = prevBucket->next;
        prevBucket->next->prev = newBucket;
        prevBucket->next = newBucket;
    }
    
    // Helper method to remove a bucket if it's empty
    void removeBucket(Bucket* bucket) {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
        countBucket.erase(bucket->count); // Remove from map
        delete bucket;
    }
    
    void inc(string key) {
        int count = 0;
        if(keyCount.find(key) != keyCount.end()){
            count = keyCount[key];
        }
        keyCount[key] = count + 1; // Increase the count
        
        Bucket* currBucket = nullptr;
        if(countBucket.find(count) != countBucket.end()){
            currBucket = countBucket[count];
        }

        Bucket* newBucket = nullptr;
        if(countBucket.find(count + 1) != countBucket.end()){
            newBucket = countBucket[count + 1];
        }
        
        if (newBucket == nullptr) {
            newBucket = new Bucket(count + 1);
            countBucket[count + 1] = newBucket;
            if (currBucket == nullptr) {
                addBucketAfter(newBucket, head); // First entry, add after head
            } else {
                addBucketAfter(newBucket, currBucket); // Add newBucket after currBucket
            }
        }
        
        newBucket->keys.insert(key); // Add the key to the new bucket
        
        if (currBucket != nullptr) {
            currBucket->keys.erase(key); // Remove key from the old bucket
            if (currBucket->keys.empty()) {
                removeBucket(currBucket); // Remove bucket if no keys remain
            }
        }
    }
    
    void dec(string key) {
        int count = keyCount[key]; // Get current count of the key
        if (count == 1) {
            keyCount.erase(key); // Remove key from the map if count is 1
        } else {
            keyCount[key] = count - 1; // Decrease the count
        }
        
        Bucket* currBucket = countBucket[count];
        Bucket* newBucket = nullptr;
        if(countBucket.find(count - 1) != countBucket.end()){
            newBucket = countBucket[count - 1];
        }
        
        if (count > 1 && newBucket == nullptr) {
            newBucket = new Bucket(count - 1);
            countBucket[count - 1] = newBucket;
            addBucketAfter(newBucket, currBucket->prev); // Add new bucket before currBucket
        }
        
        if (newBucket != nullptr) {
            newBucket->keys.insert(key); // Add key to the new bucket
        }
        
        currBucket->keys.erase(key); // Remove key from the old bucket
        if (currBucket->keys.empty()) {
            removeBucket(currBucket); // Remove bucket if no keys remain
        }
    }
    
    string getMaxKey() {
        if (tail->prev == head) {
            return ""; // No elements in the list
        }
        return *(tail->prev->keys.begin()); // Get any key from the last bucket
    }
    
    string getMinKey() {
        if (head->next == tail) {
            return ""; // No elements in the list
        }
        return *(head->next->keys.begin()); // Get any key from the first bucket
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

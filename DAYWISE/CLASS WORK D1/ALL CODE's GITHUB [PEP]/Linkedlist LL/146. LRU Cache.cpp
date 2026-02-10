#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct Node{
        int key, value;
        Node *next, *prev;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;
    int capacity;

    void remove(Node* node){
        map.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // In C++, we might want to delete the node to avoid memory leaks, 
        // but the insert implementation below reuses 'new Node' on every insert. 
        // However, the Java code relies on GC. 
        // For strict C++, we should delete `node` here if it is not going to be reused. 
        // But looking at `put`, Java code does: `remove(map.get(key)); ... insert(new Node(key,value));`.
        // So yes, we should delete it.
        delete node; 
    }

    void insert(Node* node){
        map[node->key] = node;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node* node = map[key];
            // To emulate Java logic: remove then insert. 
            // In Java code: remove(node); insert(node); 
            // The Java remove just unlinks. It does not delete.
            // My remove() above deletes. So I cannot pass 'node' to it if I want to reuse it.
            // Let's refactor remove/insert to match Java exactly (helper methods).
            
            // Refactored remove: unlink only
            map.erase(node->key);
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
            // Refactored insert: link only
            map[node->key] = node;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            
            return node->value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Node* existingNode = map[key];
            // remove logic (unlink + delete because we will create new one)
            map.erase(existingNode->key);
            existingNode->prev->next = existingNode->next;
            existingNode->next->prev = existingNode->prev;
            delete existingNode;
        }
        if(capacity == map.size()){
            Node* lru = tail->prev;
            // remove logic (unlink + delete)
            map.erase(lru->key);
            lru->prev->next = lru->next;
            lru->next->prev = lru->prev;
            delete lru;
        }
        // insert logic
        Node* newNode = new Node(key, value);
        map[newNode->key] = newNode;
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

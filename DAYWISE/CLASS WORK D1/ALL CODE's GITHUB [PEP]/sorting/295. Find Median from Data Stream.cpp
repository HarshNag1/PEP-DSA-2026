#include <queue>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class MedianFinder {
    priority_queue<int> small; // Max heap
    priority_queue<int, vector<int>, greater<int>> large; // Min heap

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(small.size() == large.size()){
        large.push(num);
        small.push(large.top());
        large.pop();
       }else{
        small.push(num);
        large.push(small.top());
        small.pop();
       }
    }
    
    double findMedian() {
        if(small.size() == large.size()){
            return (small.top() + large.top()) / 2.0;
        }
        else{
            return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#include <bits/stdc++.h>
using namespace std;

// Node class
struct Node {
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Queue class
class myQueue {
private:
    Node* front;
    Node* rear;
    int current_size;
    
public:
    myQueue() {
        // Initialize your data members
        front = nullptr;
        rear = nullptr;
        current_size = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == nullptr;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        Node* newNode = new Node(x);
        if(front == nullptr){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        current_size++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()){
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        current_size--;
    }

    int getFront() {
        // Returns the front element of the queue.
        // If queue is empty, return -1.
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return current_size;
    }
};

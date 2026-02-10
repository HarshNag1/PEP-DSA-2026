#include <iostream>

using namespace std;

/*
struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};
*/
// Assuming Node is defined.
struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if(head == nullptr){
            return nullptr;
        }
        if(x == 1){
            return head->next;
        }
        
        Node* temp = head;
        for(int i=1; i<x-1 && temp!=nullptr; i++){
            temp = temp->next;
        }
        if(temp != nullptr && temp->next != nullptr){
            temp->next = temp->next->next;
        }
        return head;
    }
};

#include <iostream>

using namespace std;

/*
struct Node
{
    int data;
    Node *next;
    Node(int d) {data = d; next = nullptr; }
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
    Node* sortedInsert(Node* head, int key) {
        Node* newNode = new Node(key);
        
        if(head == nullptr || key < head->data ){
            newNode->next = head;
            return newNode;
            
        }
        Node* curr = head;
        while(curr->next != nullptr && curr->next->data < key){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }
};

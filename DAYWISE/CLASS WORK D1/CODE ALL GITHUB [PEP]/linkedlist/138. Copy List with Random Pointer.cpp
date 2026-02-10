#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Including the definition for completeness as per pattern, though likely provided by environment.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        Node* temp = head;
        while(temp != nullptr){
            Node* n1 = new Node(temp->val);
            Node* tempp1 = temp->next;
            temp->next = n1;
            n1->next = tempp1;
            temp = tempp1;
        }
        Node* t = head;
        while(t != nullptr){
            if(t->random != nullptr){
                t->next->random = t->random->next;
            }
            t = t->next->next;
        }

        Node* h2 = head->next;
        Node* t1 = head;
        Node* t2 = head->next;

        while(t1 != nullptr){
            Node* t1p1 = t1->next->next;
            Node* t2p1 = nullptr;
            if(t2->next != nullptr) {
                t2p1 = t2->next->next;
            }

            t1->next = t1p1;
            t2->next = t2p1;
            t1 = t1p1;
            t2 = t2p1;
        }
        return h2;
    }
};

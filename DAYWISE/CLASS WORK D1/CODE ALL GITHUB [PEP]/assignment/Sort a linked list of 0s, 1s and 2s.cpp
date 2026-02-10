#include <iostream>

using namespace std;

/*
struct Node {
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {}
};
*/
// Assuming Node is defined elsewhere or should be uncommented if this was a standalone file.
// For translation, I will provide the struct but keep it commented if the original had it commented, 
// or I will assume the user has a common header. 
// However, the Java file had it commented out but used it. 
// I will include the struct definition for completeness.

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class Solution {
public:
    Node* segregate(Node* head) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == 0){
                count0++;
            }
            else if(temp->data == 1){
                count1++;
            }
            else{
                count2++;
            }
            temp = temp->next;
        }
        
        temp = head;
        while(count0-- > 0){
            temp->data = 0;
            temp = temp->next;
        }
        while(count1-- > 0){
            temp->data = 1;
            temp = temp->next;
        }
        while(count2-- > 0){
            temp->data = 2;
            temp = temp->next;
        }
        
        return head;
    }
};

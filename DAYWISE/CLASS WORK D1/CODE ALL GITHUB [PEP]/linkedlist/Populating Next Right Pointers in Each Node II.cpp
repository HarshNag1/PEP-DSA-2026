#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Assuming Node is defined.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        Node* current = root;
        while(current != nullptr){
            Node* dummy = new Node(0);
            Node* tail = dummy;

            while(current != nullptr){
                if(current->left != nullptr){
                    tail->next = current->left;
                    tail = tail->next;
                }
                if(current->right != nullptr){
                    tail->next = current->right;
                    tail = tail->next;
                }
                current = current->next;
            }
            current = dummy->next;
        }
        return root;
    }
};

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
// Assuming Node is same as defined previously or should be included.
// I'll redefine it here for the standalone file context if needed, but since it's same name, 
// if user compiles all together it might conflict. But typically these are separate files.
// I'll check if I should redefine it. Yes, these are separate files.

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
        Node* ans = root;
        while(root->left != nullptr){
            Node* temp = root;
            while(temp != nullptr){
                temp->left->next = temp->right;
                if(temp->next != nullptr){
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            root = root->left;
        }
        return ans;
    }
};

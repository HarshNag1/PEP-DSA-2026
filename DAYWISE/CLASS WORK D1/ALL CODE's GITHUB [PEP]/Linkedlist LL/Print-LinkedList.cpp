#include <vector>
#include <iostream>

using namespace std;

// GFG

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printList(Node* head) {
        // code here
        Node* temp = head;
        vector<int> ans;
        while(temp != nullptr){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        return ans;
    }
};

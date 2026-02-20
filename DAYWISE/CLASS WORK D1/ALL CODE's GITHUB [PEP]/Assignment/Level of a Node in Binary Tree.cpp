#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class Solution {
public:
    int getLevel(Node* root, int X) {
        if (root == nullptr) return 0;

        queue<Node*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                if (current->data == X)
                    return level;

                if (current->left != nullptr)
                    q.push(current->left);

                if (current->right != nullptr)
                    q.push(current->right);
            }
            level++;
        }

        return 0; 
    }
};

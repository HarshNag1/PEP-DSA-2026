#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // your code goes here
        if(root == nullptr) {
            return 0;
        }
        int leftside = maxDepth(root->left);
        int rightSide = maxDepth(root->right);
        return 1 + max(leftside, rightSide);
    }
};

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterofBT(root, diameter);
        return diameter;
    }
    
private:
    int diameterofBT(TreeNode* root, int& height) {
        if(root == nullptr) {
            return 0;
        }
        
        int lh = diameterofBT(root->left, height);
        int rh = diameterofBT(root->right, height);
        
        height = max(height, lh + rh);
        
        return 1 + max(lh, rh);
    }
};

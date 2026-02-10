#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        flattn(root);
    }
    
    TreeNode* flattn(TreeNode* root){
        if(root == nullptr) return nullptr;
        
        TreeNode* lt = flattn(root->left);
        TreeNode* rt = flattn(root->right);
        
        if(lt == nullptr && rt == nullptr) return root;
        else if(lt == nullptr && rt != nullptr) return rt;
        else if(lt != nullptr && rt == nullptr){
            TreeNode* lc = root->left;
            root->right = lc;
            root->left = nullptr;
            return lt;
        } else {
            TreeNode* lc = root->left;
            TreeNode* rc = root->right;
            root->right = lc;
            root->left = nullptr;
            lt->right = rc;
            return rt;
        }
    }
};

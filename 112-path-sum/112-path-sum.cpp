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
    
    void mo(TreeNode* root, int sm, int tar, int &fl) {
        if(!root) {
            return;
        }
        sm += root->val;
        if(!root->left && !root->right && sm == tar) {
            fl = 1;
        }
        mo(root->left, sm, tar, fl);
        mo(root->right, sm, tar, fl);
    }
    
    bool hasPathSum(TreeNode* root, int tar) {
        int fl = 0;
        mo(root, 0, tar, fl);
        return fl == 1 ? true : false;
    }
};
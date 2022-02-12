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
    
    void mo(TreeNode* root, int level, int &mn) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            mn = min(level, mn);
        }
        mo(root->left, level+1, mn);
        mo(root->right, level+1, mn);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int mn = INT_MAX;
        mo(root, 1, mn);
        return mn;
    }
};
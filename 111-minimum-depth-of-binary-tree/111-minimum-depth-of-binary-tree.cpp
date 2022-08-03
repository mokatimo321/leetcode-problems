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
    
    void get_min(TreeNode* root, int level, int &min_level) {
        
        if(!root) {
            return;
        }
        
        if(!root->left && !root->right) {
            min_level = min(min_level, level);
        }
        
        get_min(root->left, level+1, min_level);
        get_min(root->right, level+1, min_level);
        
        
    }
    
    
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int min_level = INT_MAX;
        get_min(root, 1, min_level);
        return min_level;
    }
};
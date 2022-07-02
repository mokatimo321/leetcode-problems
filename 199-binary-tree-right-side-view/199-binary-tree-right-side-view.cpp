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
    
    void right_view(TreeNode *root, vector<int> &result, int level, int &max_level) {
        
        if(!root) {
            return;
        }
        
        if(level > max_level) {
            result.push_back(root->val);
            max_level = level;
        }
        
        right_view(root->right, result, level+1, max_level);
        right_view(root->left, result, level+1, max_level);
        
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        int max_level = 0;
        right_view(root, result, 1, max_level);
        return result;
        
    }
};
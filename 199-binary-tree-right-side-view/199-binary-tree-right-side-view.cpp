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
    
    void right_view(TreeNode *root, int level, int &max_level, vector<int> &result) {
        
        if(!root) {
            return;
        }
        
        
        if(level > max_level) {
            max_level = level;
            result.push_back(root->val);
        }
        
        right_view(root->right, level+1, max_level, result);
        right_view(root->left, level+1, max_level, result);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int max_level = 0;
        right_view(root, 1, max_level, result);
        return result;
    }
};
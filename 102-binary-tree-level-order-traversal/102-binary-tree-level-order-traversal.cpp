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
    
    void level_order(TreeNode* root, vector<vector<int>> &result, int level, int &max_level) {
        
        //base case
        if(!root) {
            return;
        }
        
        if(level > max_level) {
            max_level = level;
            result.push_back({root->val});
        }
        else {
            result[level-1].push_back(root->val);
        }
        
        level_order(root->left, result, level+1, max_level);
        level_order(root->right, result, level+1, max_level);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int max_level = 0;
        level_order(root, result, 1, max_level);
        return result;
    }
};
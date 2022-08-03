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
    
    void traverse(TreeNode* root, int sm, vector<int> fill, vector<vector<int>> &result) {
        
        //base case
        if(!root) {
            return;
        }
        
        sm -= root->val;
        fill.push_back(root->val);
        
        if(sm == 0 && !root->left && !root->right) {
            result.push_back(fill);
        }
        
        traverse(root->left, sm, fill, result);
        traverse(root->right, sm, fill, result);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        traverse(root, targetSum, {}, result);
        return result;
    }
};
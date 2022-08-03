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
    
    void traverse(TreeNode* root, vector<vector<int>> &result, int level, int &max_level) {
        
        //if root == NULL
        if(!root) {
            return;
        }
        
        if(level > max_level) {
            result.push_back({root->val});
            max_level = level;
        }
        else {
            if(level %2 == 0) {
                result[level-1].insert(result[level-1].begin(), root->val);
            }
            else {
                result[level-1].push_back(root->val);
            }
        }
        
        traverse(root->left, result, level+1, max_level);
        traverse(root->right, result, level+1, max_level);
        
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int max_level = 0;
        traverse(root, result, 1, max_level);
        return result;
    }
};
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
    
    int cnt = 0;
    
    pair<int, int> vs(TreeNode*root) {
        if(root == NULL) {
            return {0, 0};
        }
        auto left = vs(root->left);
        auto right = vs(root->right);
        int sm = left.first + right.first+root->val;
        int n = left.second+right.second+1;
        cnt += sm/n == root->val;
        return {sm, n};
        
    }
    
    
    int averageOfSubtree(TreeNode* root) {
        auto p = vs(root);
        return cnt;
    }
};
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
private:
    vector<vector<int>> momo;
public:
    
    void mo(TreeNode* root, int sm, int tar, vector<int> m) {
        if(!root) {
            return;
        }
        sm += root->val;
        m.push_back(root->val);
        if(sm == tar && !root->left && !root->right) {
            momo.push_back(m);
        }
        mo(root->left, sm, tar, m);
        mo(root->right, sm, tar, m);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<int> m;
        mo(root, 0, tar, m);
        return momo;
    }
};
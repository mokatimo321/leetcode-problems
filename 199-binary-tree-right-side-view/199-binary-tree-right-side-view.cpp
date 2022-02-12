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
    
    void mo(TreeNode* root, int level, int &mx, vector<int> &m) {
        if(!root) {
            return;
        }
        if(level > mx) {
            mx = level;
            m.push_back(root->val);
        }
        mo(root->right, level+1, mx, m);
        mo(root->left, level+1, mx, m);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> m;
        int mx = 0;
        mo(root, 1, mx, m);
        return m;
    }
};
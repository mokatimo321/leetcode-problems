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
    
    void mo(TreeNode* root, string s, vector<string> &m) {
        if(!root) {
            return;
        }
        if(s.length() > 0) {
            s += "->";
        }
        s += to_string(root->val);
        if(!root->left && !root->right) {
            m.push_back(s);
        }
        mo(root->left, s, m);
        mo(root->right, s, m);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> m;
        mo(root, "", m);
        return m;
    }
};
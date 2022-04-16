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
    
    void mo(TreeNode* root, int &sm) {
        if(root == NULL) {
            return;
        }
        mo(root->right, sm);
        sm += root->val;
        root->val = sm;
        mo(root->left, sm);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        int sm = 0;
        mo(root, sm);
        return root;
    }
};
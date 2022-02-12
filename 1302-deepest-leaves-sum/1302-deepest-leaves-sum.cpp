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
    
    int htt(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int lh = htt(root->left);
        int rh = htt(root->right);
        return max(lh, rh) + 1;
    }
    
    void mo(TreeNode* root, int level, int ht, int &sm) {
        if(root == NULL) {
            return;
        }
        if(level == ht) {
            sm += root->val;
        }
        mo(root->left, level+1, ht, sm);
        mo(root->right, level+1, ht, sm);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ht = htt(root);
        int sm = 0;
        mo(root, 1, ht, sm);
        return sm;
    }
};
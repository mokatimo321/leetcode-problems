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
    
    int isLeaf(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }
        return 0;
    }
    
    void mo(TreeNode* root, int sm, int &sum) {
        if(root == NULL) {
            return;
        }
        sm = sm*10 + root->val;
        if(isLeaf(root)) {
            sum += sm;
        }
        mo(root->left, sm, sum);
        mo(root->right, sm, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        mo(root, 0, sum);
        return sum;
    }
};
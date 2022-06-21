/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* Traverse(TreeNode* root, int p, int q) {
        
        if(!root) {
            return NULL;
        }
        
        if(root->val == p || root->val == q) {
            return root;
        }
        
        TreeNode* left = Traverse(root->left, p, q);
        TreeNode* right = Traverse(root->right, p, q);
        
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else {
            return root;
        }
        
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Traverse(root, p->val, q->val);
    }
};
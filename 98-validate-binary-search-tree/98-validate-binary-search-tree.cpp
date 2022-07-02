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
    
    //we will be using the concept of max & min to pass to the function and check it for the respective nodes
    bool BSThelper(TreeNode *root, long min, long max) {
        
        //to heck if the node exists
        if(!root) {
            return true;
        }
                
        //check for BST Conditions
        if(root->val <= min || root->val >= max) {
            return false;
        }
        
        
        //final recur case
        return BSThelper(root->left, min, root->val) && BSThelper(root->right, root->val, max);
        
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        long min = LONG_MIN, max = LONG_MAX;
        return BSThelper(root, min, max);
        
    }
};
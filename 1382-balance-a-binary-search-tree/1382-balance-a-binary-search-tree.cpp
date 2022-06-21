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
    
    void Traverse(TreeNode* root, vector<int> &res) {
        
        //if not root
        if(!root) {
            return;
        }
        
        Traverse(root->left, res);
        res.push_back(root->val);
        Traverse(root->right, res);
        
    }
    
    TreeNode* Helper(vector<int> values, int low, int high) {
        
        if(high < low) {
            return NULL;
        }
        
        int mid = low + (high - low)/2;
        
        TreeNode* root = new TreeNode(values[mid]);
        root->left = Helper(values, low, mid - 1);
        root->right = Helper(values, mid + 1, high);
        
        return root;
        
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> values;
        Traverse(root, values);
        
        //we get the sorted values of the BST
        return Helper(values, 0, values.size() -1);
        
        
    }
};
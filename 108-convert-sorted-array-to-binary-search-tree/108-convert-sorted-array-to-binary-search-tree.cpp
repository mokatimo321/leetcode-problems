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
    
    TreeNode* tree_maker(vector<int> nums, int low, int high) {
        
        if(low > high) {
            return NULL;
        }
        
        int mid = low + (high - low)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = tree_maker(nums, low, mid - 1);
        root->right = tree_maker(nums, mid + 1, high);
        
        return root;
        
    }
    
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return tree_maker(nums, 0, nums.size() - 1);
        
    }
};
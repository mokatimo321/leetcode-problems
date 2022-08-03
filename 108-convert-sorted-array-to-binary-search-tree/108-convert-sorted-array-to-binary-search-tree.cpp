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
    
    TreeNode* create(vector<int> nums, int start, int end) {
        
        if(start > end) {
            return NULL;
        }
        
        int mid = start + (end - start)/2;
        TreeNode* new_node = new TreeNode(nums[mid]);
        
        if(start == end) {
            return new_node;
        }
        
        new_node->left = create(nums, start, mid-1);
        new_node->right = create(nums, mid+1, end);
        
        return new_node;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};
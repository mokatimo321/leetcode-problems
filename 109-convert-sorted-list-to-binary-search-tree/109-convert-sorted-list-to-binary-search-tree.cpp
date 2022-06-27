/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* make_tree(vector<int> nums, int low, int high) {
        
        if(low > high) {
            return NULL;
        }
        
        int mid = low + (high - low)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = make_tree(nums, low, mid - 1);
        root->right = make_tree(nums, mid + 1, high);
        
        return root;
        
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> nums;
        ListNode* p = head;
        while(p) {
            nums.push_back(p->val);
            p = p->next;
        }
        
        int low = 0, high = nums.size() - 1;
        return make_tree(nums, low, high);
        
        
    }
};
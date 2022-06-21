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
    
    int search(vector<int> nums, int start, int end, int val) {
        int i = 0;
        for(i = start;i<=end;i++) {
            if(nums[i] > val) {
                return i;
            }
        }
        return i;
    }
    
    TreeNode* mo(vector<int> nums, int start, int end, int &pre_index) {
        
        if(pre_index >= nums.size() || start > end) {
            return NULL;
        }
        
        TreeNode* new_node = new TreeNode(nums[pre_index++]);
        
        if(start == end) {
            return new_node;
        }
        
        int index = search(nums, start, end, new_node->val);
        //pre_index++;
        //cout<<index<<endl;
        
        new_node->left = mo(nums, start+1, index-1, pre_index);
        new_node->right = mo(nums, index, end, pre_index);
        
        return new_node;
        
        
    }
    
//     int search(vector<int> nums, int start, int end, int val) {
//         int i = 0;
//         for(i = start;i<=end;i++) {
//             if(nums[i] > val) {
//                 return i;
//             }
//         }
//         return i;
//     }
    
    
//     TreeNode* momo(vector<int> nums, int start, int end, int &pre_index) {
        
//         if(pre_index >= nums.size() || start > end) {
//             return NULL;
//         }
        
//         TreeNode *new_node = new TreeNode(nums[pre_index]);
//         pre_index++;
        
//         if(start == end) {
//             return new_node;
//         }
        
//         int i = search(nums, start, end, new_node->val);
        
//         new_node->left = momo(nums, start+1, i-1, pre_index);
//         new_node->right = momo(nums, i, end, pre_index);
        
//         return new_node;
        
//     }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pre_index = 0;
        return mo(preorder, 0, preorder.size() - 1, pre_index);
    }
};

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
    
    int search(vector<int> inorder, int val) {
        for(int i = 0;i<inorder.size();i++) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* create(vector<int> preorder, vector<int> inorder, int start, int end, int &pre_index) {
        
        if(start > end) {
            return NULL;
        }
        
        TreeNode* new_node = new TreeNode(preorder[pre_index++]);
        
        if(start == end) {
            return new_node;
        }
        
        int index = search(inorder, new_node->val);
        
        new_node->left = create(preorder, inorder, start, index-1, pre_index);
        new_node->right = create(preorder, inorder, index+1, end, pre_index);
        
        return new_node;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_index = 0;
        return create(preorder, inorder, 0, inorder.size() - 1, pre_index);
    }
};
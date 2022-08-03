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
    
    unordered_map<int, int> mp;
    
    TreeNode *create(vector<int> inorder, vector<int> postorder, int start, int end, int &post_index) {
        
        if(start > end) {
            return NULL;
        }
        
        TreeNode *new_node = new TreeNode(postorder[post_index--]);
        
        if(start == end) {
            return new_node;
        }
        
        int index = mp[new_node->val];
        
        new_node->right = create(inorder, postorder, index+1, end, post_index);
        new_node->left = create(inorder, postorder, start, index-1, post_index);
        
        return new_node;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        int post_index = postorder.size() - 1;
        return create(inorder, postorder, 0, inorder.size() - 1, post_index);
    }
};
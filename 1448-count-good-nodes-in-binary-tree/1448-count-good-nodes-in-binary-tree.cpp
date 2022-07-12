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
    
    void count_good(TreeNode* root, int max_val, int& cnt) {
        
        //if not root
        if(!root) {
            return;
        }
        
        
        //check for max nodes
        if(root->val >= max_val) {
            max_val = root->val;
            cnt++;
            //cout<<root->val<<endl;
        }
        
        count_good(root->left, max_val, cnt);
        count_good(root->right, max_val, cnt);
        
    }
    
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        count_good(root, INT_MIN, cnt);
        return cnt;
    }
};
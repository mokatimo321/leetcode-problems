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
    
    TreeNode* LCA(TreeNode* root, int p, int q) {
        
        //if not root
        if(!root) {
            return NULL;
        }
        
        //if we get the value matched
        if(root->val == p || root->val == q) {
            return root;
        }
        
        //recur for left & right Subtree
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        
        //result
        if(!left) {
            return right;
        }
        else if(!right) {
            return left;
        }
        return root;
        
    }
    
    bool traverse(TreeNode* root, int val, string &ans) {
        
        if(!root) {
            return false;
        }
        
        if(root->val == val) {
            return true;
        }
        
        //trying to find "L"
        ans += "L";
        
        if(traverse(root->left, val, ans)) {
            return true;
        }
        
        ans.pop_back();
        
        ans += "R";
        
        if(traverse(root->right, val, ans)) {
            return true;
        }
        
        ans.pop_back();
        
        return false;
        
        
    }
    
    
    string getDirections(TreeNode* root, int st, int dt) {
        
        string ans = "";
        
        TreeNode* lca = LCA(root, st, dt);
        traverse(lca, st, ans);
        for(int i = 0;i<ans.length();i++) {
            ans[i] = 'U';
        }
        traverse(lca, dt, ans);
        return ans;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void traverse(Node* root, vector<vector<Node*>> &memo, int level, int &max_level) {
        
        if(!root) {
            return;
        }
        
        if(level > max_level) {
            max_level = level;
            memo.push_back({root});
        }
        else {
            memo[level-1].back()->next = root;
            memo[level-1].push_back(root);
        }
        
        traverse(root->left, memo, level+1, max_level);
        traverse(root->right, memo, level+1, max_level);
        
    }
    
    Node* connect(Node* root) {
        
        vector<vector<Node*>> memo;
        int max_level = 0;
        
        traverse(root, memo, 1, max_level);
        return root;
    }
};
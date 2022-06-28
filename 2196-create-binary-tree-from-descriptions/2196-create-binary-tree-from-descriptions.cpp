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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        
        //let us store the parnts data in a hashmap
        unordered_map<int, vector<int>> mp;
        
        //another hashmap to track the root node by storing the child nodes
        unordered_map<int, int> child;
        vector<int> parent;
        
        
        for(int i = 0;i<desc.size();i++) {
            child[desc[i][1]]++;
            parent.push_back(desc[i][0]);
            if(desc[i][2] == 0) {
                mp[desc[i][0]].push_back(desc[i][1]);
            }
            else {
                mp[desc[i][0]].push_back(desc[i][1]*-1);
            }
        }
        
        // for(auto x : mp) {
        //     cout<<x.first<<endl;
        //     for(int i = 0;i<x.second.size();i++) {
        //         cout<<x.second[i]<<endl;
        //     }
        //     cout<<"----------------"<<endl;
        // }
        
        //root_val to store the value of root node
        int root_val = 0;
        
        for(int i = 0;i<parent.size();i++) {
            if(child.find(parent[i]) == child.end()) {
                root_val = parent[i];
                break;
            }
        }
        
        //queue to build the tree
        queue<TreeNode*> q;
        
        
        //let us make the root node
        TreeNode *root = new TreeNode(root_val);
        q.push(root);
        
        
        while(q.size() > 0) {
            
            TreeNode *temp = q.front();
            //cout<<temp->val<<"---------"<<endl;
            q.pop();
            
            //to build the tree
            if(mp.find(temp->val) != mp.end())
                if(mp[temp->val].size() == 2) {
                    if(mp[temp->val][0] < 0) {
                        TreeNode *left_node = new TreeNode(abs(mp[temp->val][0]));
                        temp->left = left_node;
                        //cout<<left_node->val<<endl;
                        q.push(left_node);
                        TreeNode *right_node = new TreeNode(mp[temp->val][1]);
                        //cout<<right_node->val<<endl;
                        temp->right = right_node;
                        q.push(right_node);
                    }
                    else {
                        TreeNode *left_node = new TreeNode(abs(mp[temp->val][1]));
                        temp->left = left_node;
                        //cout<<left_node->val<<endl;
                        q.push(left_node);
                        TreeNode *right_node = new TreeNode(mp[temp->val][0]);
                        //cout<<right_node->val<<endl;
                        temp->right = right_node;
                        q.push(right_node);
                    }
                }
                else {
                    if(mp[temp->val][0] < 0) {
                        TreeNode *left_node = new TreeNode(abs(mp[temp->val][0]));
                        //cout<<left_node->val<<endl;
                        temp->left = left_node;
                        q.push(left_node);
                        temp->right = NULL;
                    }
                    else {
                        TreeNode *right_node = new TreeNode(mp[temp->val][0]);
                        //cout<<right_node->val<<endl;
                        temp->right = right_node;
                        q.push(right_node);
                        temp->left = NULL;
                    }
                }
            else {
                temp->left = NULL;
                temp->right = NULL;
            }
            
        }
        
        return root;
        
    }
};
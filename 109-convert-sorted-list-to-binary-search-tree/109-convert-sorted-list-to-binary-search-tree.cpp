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
    
    int get_val(ListNode* head, int index) {
        
        int cnt = 0;
        while(head) {
            if(index == cnt) {
                return head->val;
            }
            cnt++;
            head = head->next;
        }
        
        return -1;
        
    }
    
    TreeNode* create(ListNode* head, int start, int end) {
        
        if(start > end) {
            return NULL;
        }
        
        int mid = start + (end - start)/2;
        
        TreeNode* new_node = new TreeNode(get_val(head, mid));
        
        if(start == end) {
            return new_node;
        }
        
        new_node->left = create(head, start, mid-1);
        new_node->right = create(head, mid+1, end);
        
        return new_node;
        
    }
    
    int get_length(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        return create(head, 0, get_length(head) - 1);
    }
};
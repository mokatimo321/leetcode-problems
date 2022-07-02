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
class Solution {
public:
    
    bool helper(ListNode *p, ListNode *&q) {
        
        if(p == NULL) {
            return true;
        }
        
        bool isPalindrome = helper(p->next, q) && p->val == q->val;
        q = q->next;
        return isPalindrome;
        
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *p = head, *q = head;
        return helper(p, q);
    }
};
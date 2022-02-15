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
    
    void mo(ListNode *p, ListNode* &q, bool &res) {
        if(p == NULL) {
            return;
        }
        mo(p->next, q, res);
        if(p->val != q->val) {
            res = false;
        }
        q = q->next;
    }
    
    bool isPalindrome(ListNode* head) {
        bool res = true;
        ListNode* q = head;
        mo(head, q, res);
        return res;
    }
};
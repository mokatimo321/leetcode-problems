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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy_head = new ListNode();
        ListNode *last = dummy_head;
        
        ListNode *p = l1;
        ListNode *q = l2;
        
        if(!p && !q) {
            return NULL;
        }
        else if(!p) {
            return q;
        }
        else if(!q) {
            return p;
        }
        
        while(p != NULL && q != NULL) {
            if(p->val > q->val) {
                last->next = q;
                last = q;
                q = q->next;
            }
            else {
                last->next = p;
                last = p;
                p = p->next;
            }
        }
        
        if(p == NULL) {
            last->next = q;
        }
        
        if(q == NULL) {
            last->next = p;
        }
        
        dummy_head = dummy_head->next;
        return dummy_head;
    }
};
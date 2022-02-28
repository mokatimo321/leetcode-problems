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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *p = head, *q = head;
        ListNode *last;
        
        while(n) {
            p = p->next;
            n--;
        }
        
        if(!p) {
            return head->next;
        }
        
        while(p) {
            last = q;
            q = q->next;
            p = p->next;
        }
        
        last->next = q->next;
        
        return head;
    }
};
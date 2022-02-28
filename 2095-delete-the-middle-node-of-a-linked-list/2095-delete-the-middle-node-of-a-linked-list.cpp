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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head->next) {
            return NULL;
        }
        
        ListNode *p = head, *q = head;
        ListNode *last = q;
        
        while(p) {
            p = p->next;
            if(p) {
                last = q;
                q = q->next;
            }
            else {
                break;
            }
            p = p->next;
        }
        
        last->next = q->next;
        
        return head;
    }
};
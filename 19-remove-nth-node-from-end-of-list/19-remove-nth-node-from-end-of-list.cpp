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
        if(head == NULL) {
            return head;
        }
        
        int c = 0;
        struct ListNode *p = head;
        
        while(p != NULL) {
            c++;
            if(c == n) {
                break;
            }
            p = p->next;
        }
        
        struct ListNode *q = head;
        struct ListNode *r;
        
        while(p->next != NULL) {
            c++;
            r = q;
            q = q->next;
            p = p->next;
        }
        
        if(n == c) {
            return head->next;
        }
        
        r->next = q->next;
        
        
        return head;
    }
};
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
    ListNode* oddEvenList(ListNode* head) {
        struct ListNode *odd = new ListNode();
        struct ListNode *even = new ListNode();
        
        struct ListNode *lo = odd;
        struct ListNode *le = even;
        
        int c = 0;
        
        if(head == NULL) {
            return head;
        }
        
        struct ListNode *p = head;
        
        if(head->next == NULL) {
            return head;
        }
        
        while(p != NULL) {
            c++;
            if(c %2 == 0) {
                le->next = p;
                le = p;
            }
            else {
                lo->next = p;
                lo = p;
            }
            p = p->next;
        }
        
        head = odd->next;
        lo->next = even->next;
        le->next = NULL;
        
        return head;
        
        
    }
};
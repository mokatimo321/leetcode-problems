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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy_head(0);
        ListNode *p = &dummy_head;
        
        int extra = 0;
        int sum = 0;
        int a = 0;
        int b = 0;
        while(l1 || l2 || extra) {
            if(l1) {
                a = l1->val;
            }
            else {
                 a = 0;
            }
            
            if(l2) {
                b = l2->val;
            }
            else {
                b = 0;
            }
            sum = a + b + extra;
            extra = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            if(l1 != nullptr) {
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy_head.next;
    }
};
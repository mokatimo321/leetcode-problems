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
        ListNode *p = l1, *q = l2;
        ListNode *last_p, *last_q;
        int len1 = 1, len2 = 1;
        int carry = 0;
        while(p || q) {
            int a = 0, b = 0;
            if(p) {
                a = p->val;
            }
            if(q) {
                b = q->val;
            }
            int temp = (a + b + carry);
            if(p) {
                p->val = temp % 10;
                last_p = p;
                p = p->next;
                len1++;
            }
            if(q) {
                q->val = temp % 10;
                last_q = q;
                q = q->next;
                len2++;
            }
            carry = temp / 10;
        }
        if(carry) {
            if(len1 > len2) {
                ListNode *new_node = new ListNode(carry);
                last_p->next = new_node;
            }
            else {
                ListNode *new_node = new ListNode(carry);
                last_q->next = new_node;
            }
        }
        return len1 > len2 ? l1 : l2;
    }
};
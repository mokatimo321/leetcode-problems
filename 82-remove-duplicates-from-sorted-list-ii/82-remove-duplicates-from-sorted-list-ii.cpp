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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode *dummy_head = new ListNode();
        ListNode *last = dummy_head;
        
        ListNode *p = head;
        int temp = 0;
        
        while(p) {
            if(!p->next || p->val != p->next->val) {
                last->next = p;
                last = p;
                p = p->next;
            }
            else {
                temp = p->val;
                while(p && p->val == temp) {
                    p = p->next;
                }
            }
        }
        last->next = nullptr;
        return dummy_head->next;
    }
};
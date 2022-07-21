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
    
    ListNode* pair(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* NextSwapped = swapPairs(head->next->next);
        ListNode* p = head;
        ListNode* q = head->next;
        q->next = p;
        p->next = NextSwapped;
        
        return q;
        
    }
    
    
    ListNode* swapPairs(ListNode* head) {
        
        return pair(head);
        
    }
};
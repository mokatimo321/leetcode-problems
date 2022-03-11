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
    
    int len(ListNode* p) {
        int cnt = 0;
        while(p) {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!k || !head) {
            return head;
        }
        
        int cnt = len(head);
        k = k%cnt;
        
        ListNode *p = head, *q = head;
        while(k) {
            p = p->next;
            k--;
        } 
        if(!p) {
            return head;
        }
        while(p->next) {
            q = q->next;
            p = p->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};
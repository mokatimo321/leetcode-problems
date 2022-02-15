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
    
    int cnt(ListNode *p) {
        int c = 0;
        while(p != NULL) {
            c++;
            p = p->next;
        }
        return c;
    }
    
    int carry = 0;
    
    void add(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) {
            return;
        }
        add(l1->next, l2->next);
        int temp = l1->val + l2->val + carry;
        l1->val = temp%10;
        carry = temp/10;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int x1 = cnt(l1);
        int x2 = cnt(l2);
        
        if(x1 > x2) {
            int temp = x1 - x2;
            ListNode *dummy_head = new ListNode();
            ListNode *last = dummy_head;
            temp--;
            while(temp) {
                ListNode *new_node = new ListNode();
                last->next = new_node;
                last = new_node;
                temp--;
            }
            last->next = l2;
            l2 = dummy_head;
        }
        else if(x2 > x1) {
            int temp = x2 - x1;
            ListNode *dummy_head = new ListNode();
            ListNode *last = dummy_head;
            temp--;
            while(temp) {
                ListNode *new_node = new ListNode();
                last->next = new_node;
                last = new_node;
                temp--;
            }
            last->next = l1;
            l1 = dummy_head;
        }
        
        add(l1, l2);
        
        if(carry > 0) {
            ListNode * new_node = new ListNode(carry);
            new_node->next = l1;
            l1 = new_node;
        }
        
        return l1;
        
    }
};
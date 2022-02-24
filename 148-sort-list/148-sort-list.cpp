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
    ListNode* sortList(ListNode* head) {
        
        vector<int> m;
        
        ListNode *p = head;
        
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        while(p != NULL) {
            m.push_back(p->val);
            p = p->next;
        }
        
        sort(m.begin(), m.end());
        
        ListNode *dummy_head = new ListNode();
        ListNode *last = dummy_head;
        
        for(int i = 0;i<m.size();i++) {
            ListNode *new_node = new ListNode(m[i]);
            new_node->next = NULL;
            last->next = new_node;
            last = new_node;
        }
        
        
        return dummy_head->next;
        
        
        
    }
};
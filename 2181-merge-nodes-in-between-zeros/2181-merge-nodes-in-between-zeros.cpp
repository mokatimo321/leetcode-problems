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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* start = head;
        ListNode* late_start = start;
        int present_sum = 0;
        
        ListNode* p = head->next;
        
        while(p) {
            
            if(p->val != 0) {
                present_sum += p->val;
            }
            else {
                start->val = present_sum;
                present_sum = 0;
                late_start = start;
                start = start->next;
            }
            
            p = p->next;
            
        }
        
        //cout<<start->val<<endl;
        late_start->next = NULL;
        //start = NULL;
        
        return head;
        
    }
};
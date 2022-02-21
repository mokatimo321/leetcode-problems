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
    
    ListNode* mid(ListNode *head, ListNode *tail) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        
        ListNode* p = head1;
        ListNode* q = head2;
        
        if(!p && !q) {
            return NULL;
        }
        
        ListNode* dummy_head = new ListNode();
        ListNode* last = dummy_head;
        
        while(p != NULL && q != NULL) {
            if(p->val <= q->val) {
                last->next = p;
                last = p;
                p = p->next;
            }
            else {
                last->next = q;
                last = q;
                q = q->next;
            }
        }
        
        if(p) {
            last->next = p;
        }
        else {
            last->next = q;
        }
        
        return dummy_head->next;
        
    }
    
    ListNode* merge_sort(ListNode *head, ListNode *tail) {
        
        if(head == tail) {
            ListNode* new_node = new ListNode(head->val);
            return new_node;
        }
        
        ListNode* md = mid(head, tail);
        ListNode* first_half = merge_sort(head, md);
        ListNode* second_half = merge_sort(md->next, tail);
        ListNode *res = merge(first_half, second_half);
        return res;
        
    }
    
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummy_head = new ListNode();
        ListNode *last = dummy_head;
        
        for(int i = 0;i<lists.size();i++) {
            last->next = lists[i];
            while(last->next != NULL) {
                last = last->next;
            }
        }
        
        last->next = NULL;
        //cout<<last->val<<endl;
        
        ListNode *p = dummy_head->next;
        
        if(p == NULL) {
            return NULL;
        }
        
        return merge_sort(p, last);
        
    }
};
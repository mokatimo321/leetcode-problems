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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p = head;
        ListNode *x, *y;
        int c = 0;
        while(p != NULL) {
            c++;
            if(c == k) {
                x = p;
            }
            p = p->next;
        }
        //cout<<c<<endl;
        c = c-k+1;
        int cnt = 0;
        p = head;
        while(p != NULL) {
            cnt++;
            if(cnt == c) {
                y = p;
                break;
            }
            p = p->next;
        }
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        return head;
    }
};
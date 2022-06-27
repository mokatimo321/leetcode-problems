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
    
    int len_LL(ListNode* head) {
        ListNode*p = head;
        int cnt = 0;
        while(p) {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    
    
    int numComponents(ListNode* head, vector<int>& nums) {
        
        //we will use map as a hashmap
        vector<int> map(len_LL(head), 0);
        for(int i = 0;i<nums.size();i++) {
            map[nums[i]] += 1;
        }
        // unordered_map<int, int> map;
        // for(auto x : nums) {
        //     map[x]++;
        // }
        
        //p to traverse the LL
        ListNode* p = head;
        int cnt = 0, sz = nums.size();
        
        //Let's Traverse 
        while(p) {
            
            if(map[p->val] > 0) {
                //cout<<p->val<<endl;
                cnt++;
            }
            else {
                if(cnt > 0) {
                    cnt--;
                    sz -= cnt;
                }
                cnt = 0;
            }
            
            p = p->next;
            
        }
        
        if(cnt > 0) {
            cnt--;
            sz -= cnt;
            cnt = 0;
        }
        
        return sz;
        
    }
};
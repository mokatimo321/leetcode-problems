class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        
        stack<int> st1;
        stack<int> st2;
        
        vector<int> target(nums.size(), 0);
        
        st1.push(nums[0]);
        st2.push(0);
        
        for(int i = 1;i<nums.size();i++) {
            
            if(nums[i] <= st1.top()) {
                target[st2.top()] = nums[i];
                st1.pop();
                st2.pop();
                
                while(st1.size() > 0) {
                    if(st1.top() >= nums[i]) {
                        target[st2.top()] = nums[i];
                        st1.pop();
                        st2.pop();
                    }
                    else {
                        break;
                    }
                }
            }
            st1.push(nums[i]);
            st2.push(i);
            
        }
        
        for(int i = 0;i<nums.size();i++) {
            nums[i] -= target[i];
        }
        
        return nums;
    }
};
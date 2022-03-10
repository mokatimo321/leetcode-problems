class Solution {
public:
    
    vector<int> next_grt(vector<int> nums) {
        
        stack<int> st1;
        stack<int> st2;
        
        st1.push(nums[nums.size() - 1]);
        st2.push(nums.size() - 1);
        
        vector<int> res(nums.size(), INT_MAX);
        
        for(int i = nums.size() - 2;i>=0;i--) {
            if(nums[i] < st1.top()) {
                res[i] = st2.top();
                st1.push(nums[i]);
                st2.push(i);
            }
            else {
                st1.pop();
                st2.pop();
                while(!st1.empty()) {
                    if(nums[i] < st1.top()) {
                        res[i] = st2.top();
                        st1.push(nums[i]);
                        st2.push(i);
                        break;
                    }
                    st1.pop();
                    st2.pop();
                }
                if(st1.empty()) {
                    res[i] = INT_MAX;
                    st1.push(nums[i]);
                    st2.push(i);
                }
            }
        }
        
        return res;
        
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res = next_grt(nums);
        int i = 0, j = 0;
        
        vector<int> ans;
        
        while(i < nums.size() - (k - 1)) {
            if(i > j) {
                j = i;
            }
            if(res[j] - i < k) {
                j = res[j];
            }
            else {
                ans.push_back(nums[j]);
                i++;
            }
        }
        
        return ans;
        
    }
};
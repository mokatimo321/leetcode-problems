class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> memo(nums.size(), 0);
        
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i = nums.size() - 1;i>=0;i--) {
            mn = min(mn, nums[i]);
            memo[i] = mn;
        }
        
        int first_index = 0, last_index = 0;
        int flag = 0;
        
        for(int i = 0;i<nums.size();i++) {
            mx = max(mx, nums[i]);
            if(nums[i] < mx || nums[i] > memo[i]) {
                if(flag == 0) {
                    first_index = i;
                    flag = 1;
                }
                last_index = i;
            }
        }
        
        return last_index == 0 ? 0 : (last_index - first_index) + 1;
        
    }
};
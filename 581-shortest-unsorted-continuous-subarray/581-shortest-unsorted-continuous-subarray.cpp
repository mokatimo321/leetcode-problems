class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i = 0;i<nums.size();i++) {
            mx = max(mx, nums[i]);
            left[i] = mx;
        }
        
        for(int i = nums.size() - 1;i>=0;i--) {
            mn = min(mn, nums[i]);
            right[i] = mn;
        }
        
        int first_index = 0, last_index = 0;
        int flag = 0;
        
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] < left[i] || nums[i] > right[i]) {
                if(flag == 0) {
                    first_index = i;
                    flag = 1;
                }
                last_index = i;
            }
        }
        
        if(last_index == 0) {
            return 0;
        }
        
        return (last_index - first_index) + 1;
        
    }
};
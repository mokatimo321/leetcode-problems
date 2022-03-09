class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int first_index = 0, last_index = 0;
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i = 0;i<nums.size();i++) {
            mx = max(mx, nums[i]);
            if(nums[i] < mx) {
                last_index = i;
            }
        }
        
        for(int i = nums.size() - 1;i>=0;i--) {
            mn = min(mn, nums[i]);
            if(nums[i] > mn) {
                first_index = i;
            }
        }
        
        return last_index == 0 ? 0 : (last_index - first_index) + 1;
        
    }
};
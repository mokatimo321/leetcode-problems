class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = INT_MIN, curr = 0;
        for(int i = 0;i<nums.size();i++) {
            curr += nums[i];
            if(nums[i] > curr) {
                curr = nums[i];
            }
            best = max(best, curr);
        }
        return best;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = INT_MIN, current_sum = 0;
        for(int i = 0;i<nums.size();i++) {
            current_sum += nums[i];
            best_sum = max(best_sum, current_sum);
            if(current_sum < 0) {
                current_sum = 0;
            }
        }
        return best_sum;
    }
};
class Solution {
public:
    
    int maxProfit(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int best_buy = INT_MAX, max_prof = 0;
        for(int i = 0;i<nums.size();i++) {
            best_buy = min(best_buy, nums[i]);
            max_prof = max(max_prof, nums[i] - best_buy);
            res[i] = max_prof;
        }
        int temp = max_prof;
        max_prof = 0;
        int mx = INT_MIN, best_sell = INT_MIN;
        for(int i = nums.size() - 1;i>0;i--) {
            best_sell = max(best_sell, nums[i]);
            max_prof = max(max_prof, best_sell - nums[i]);
            mx = max(mx, max_prof + res[i-1]);
        }
        return max(mx, temp);
    }
};
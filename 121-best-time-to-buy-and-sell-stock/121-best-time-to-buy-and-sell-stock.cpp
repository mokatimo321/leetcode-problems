class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int max_prof = 0, best_buy = INT_MAX;
        for(int i = 0;i<nums.size();i++) {
            best_buy = min(best_buy, nums[i]);
            max_prof = max(max_prof, nums[i] - best_buy);
        }
        return max_prof;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int best_buy = -1 * nums[0], best_sell = 0, best_rest = 0;
        for(int i = 1;i<nums.size();i++) {
            best_buy = max(best_buy, best_rest - nums[i]);
            best_rest = max(best_rest, best_sell);
            best_sell = max(best_sell, nums[i] + best_buy);
        }
        
        return max(best_rest, best_sell);
    }
};
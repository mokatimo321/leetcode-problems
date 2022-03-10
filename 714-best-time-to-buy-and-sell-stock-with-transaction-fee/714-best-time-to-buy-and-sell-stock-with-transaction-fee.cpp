class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        
        int best_buy = -1 * (nums[0]), best_sell = 0;
        
        for(int i = 1;i<nums.size();i++) {
            best_buy = max(best_buy, best_sell - nums[i]);
            best_sell = max(best_sell, ((nums[i] + best_buy) - fee));  
        }
        
        return max(best_buy, best_sell);
        
    }
};
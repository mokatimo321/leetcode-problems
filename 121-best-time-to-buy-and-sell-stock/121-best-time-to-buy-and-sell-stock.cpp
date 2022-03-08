class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy = INT_MAX, max_prof = INT_MIN;
        for(int i = 0;i<prices.size();i++) {
            best_buy = min(best_buy, prices[i]);
            max_prof = max(max_prof, prices[i] - best_buy);
        }
        return max_prof;
    }
};
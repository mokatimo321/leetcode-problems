class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //for the 2nd transaction
        vector<int> prof(prices.size()+1, 0);
        int sell_price = INT_MIN;
        int max_prof = INT_MIN;
        
        for(int i = prices.size()-1;i>=0;i--) {
            sell_price = max(sell_price, prices[i]);
            max_prof = max(max_prof, sell_price - prices[i]);
            prof[i] = max_prof;
        }

        
        //for the first transaction
        int buy_price = INT_MAX;
        max_prof = INT_MIN;
        
        for(int i = 0;i<prices.size();i++) {
            buy_price = min(buy_price, prices[i]);
            int current_prof = prices[i] - buy_price;
            max_prof = max(max_prof, current_prof + prof[i+1]);
        }
        
        return max_prof;
            
            
    }
};
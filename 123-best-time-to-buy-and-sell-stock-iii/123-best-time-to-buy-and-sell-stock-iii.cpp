class Solution {
public:
    int dp[100001][2][3];
    int f(int ind, int buy, vector<int> &prices, int n, int k) {
        if(ind == n || k==0) return 0;
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        int profit = 0;
        if(buy) {
            int ifBuy = -prices[ind] + f(ind + 1, 0, prices, n, k);
            int ifNotBuy = 0 + f(ind + 1, 1, prices, n, k);
            profit = max(ifBuy, ifNotBuy);
        }
        else {
            int ifSell = prices[ind] + f(ind + 1, 1, prices, n, k-1);
            int ifNotSell = 0 + f(ind + 1, 0, prices, n, k);
            profit = max(ifSell, ifNotSell);
        }
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return f(0, 1, prices, prices.size(), 2);
    }
};
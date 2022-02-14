class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        vector<int> dp(val.size(), 0);
        int mx = INT_MIN;
        for(int i = val.size() - 1;i>=0;i--) {
            mx = max(val[i] - i, mx);
            dp[i] = mx;
        }
        mx = INT_MIN;
        for(int i = 0;i<val.size() - 1;i++) {
            mx = max(mx, val[i] + dp[i+1] + i);
        }
        return mx;
    }
};
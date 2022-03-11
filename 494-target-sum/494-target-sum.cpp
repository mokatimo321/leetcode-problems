class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int req = (target + sum)/2;
        
        if(abs(target) > sum || (sum + target) %2 != 0) {
            return 0;
        }
        
        vector<vector<int>> dp(nums.size() + 1, vector<int> (req + 1, 0));
        
        for(int i = 0;i<dp.size();i++) {
            for(int j = 0;j<dp[0].size();j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if(i == 0) {
                    dp[i][j] = 0;
                }
                else {
                    if(nums[i-1] > j) {
                        dp[i][j] = dp[i-1][j];
                    }
                    else {
                        dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                    }
                }
            }
        }
        
        return dp[dp.size() - 1][dp[0].size() - 1];
        
    }
};
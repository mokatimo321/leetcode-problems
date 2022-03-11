class Solution {
public:
    
    int sm(vector<int> nums) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++) {
            sum += nums[i];
        }
        return sum;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = sm(nums);
        int req = (sum + target)/2;
        
        if(abs(target) > sum || (target + sum) %2 != 0) {
            return 0;
        }
        
        vector<vector<int>> dp(nums.size() + 1, vector<int> (req+1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1;i<=req;i++) {
            dp[0][i] = 0;
        }
        
        for(int i = 1;i<dp.size();i++) {
            for(int j = 0;j<dp[0].size();j++) {
                if(nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        
        for(int i = 0;i<dp.size();i++) {
            for(int j = 0;j<dp[0].size();j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[dp.size() - 1][dp[0].size() - 1];
        
    }
};
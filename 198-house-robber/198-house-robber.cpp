class Solution {
public:
    
    int robber(vector<int> nums, int index, vector<int> &dp) {
        
        //base case
        if(index >= nums.size()) {
            return 0;
        }
        
        if(dp[index] != 0) {
            return dp[index];
        }
        
        //recur case
        int rob = nums[index] + robber(nums, index+2, dp);
        int not_rob = robber(nums, index+1, dp);
        
        dp[index] = max(rob, not_rob);
        return dp[index];
        
    }
    
    int rob(vector<int>& nums) {
        
        int sm = accumulate(nums.begin(), nums.end(), 0);
        if(sm == 0) {
            return 0;
        }
        
        vector<int> dp(nums.size(), 0);
        return robber(nums, 0, dp);
    }
};
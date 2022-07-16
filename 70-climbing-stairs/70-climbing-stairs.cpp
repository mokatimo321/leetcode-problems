class Solution {
public:
    
    int climb(int n, int index, vector<int> &dp) {
        
        //base case
        if(index > n) {
            return 0;
        } 
        
        if(index == n) {
            return 1;
        }
        
        
        if(dp[index] > 0) {
            return dp[index];
        }
        
        dp[index] = climb(n, index+1, dp) + climb(n, index+2, dp);
        return dp[index];
        
    }
    
    
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return climb(n, 0, dp);
    }
};
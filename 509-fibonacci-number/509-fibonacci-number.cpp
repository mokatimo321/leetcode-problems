class Solution {
public:
    
    int fibo(int n, vector<int> &dp) {
        
        if(dp[n] >= 0) {
            return dp[n];
        }
        
        int temp = fibo(n-1, dp) + fibo(n-2, dp);
        dp[n] = temp;
        return dp[n];
        
    }
    
    int fib(int n) {
        vector<int> dp(31, -1);
        dp[0] = 0;
        dp[1] = 1;
        fibo(n, dp);
        return dp[n];
    }
};
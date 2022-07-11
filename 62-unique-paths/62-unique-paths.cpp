class Solution {
public:
    
    int travel(int r, int c, int m, int n, vector<vector<int>> &dp, int &cnt) {
        
        //base case
        //edge cases
        if(r == m || c == n || r < 0 || c < 0) {
            return 0; 
        }
        
        //condition state
        if(r == m-1 && c == n-1) {
            return 1;
        }
        
        if(dp[r][c] >= 0) {
            return dp[r][c];
        }
        
        
        //recursion state
        //for down move & right move
        dp[r][c] = travel(r+1, c, m, n, dp, cnt) + travel(r, c+1, m, n, dp, cnt);
        return dp[r][c];
        
    }
    
    
    int uniquePaths(int m, int n) {
        
        int cnt = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return travel(0, 0, m, n, dp, cnt);
        //return cnt;
        
    }
};
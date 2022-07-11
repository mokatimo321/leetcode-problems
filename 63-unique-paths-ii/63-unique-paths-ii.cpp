class Solution {
public:
    
    int travel(vector<vector<int>> grid, int r, int c, vector<vector<int>> &dp) {
        
        //base case
        
        //edge case
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return 0;
        }
        
        //obstacle case
        if(grid[r][c] == 1) {
            dp[r][c] = 0;
            return dp[r][c];
        }
        
        //condition state
        if(r == grid.size() - 1 && c == grid[0].size() - 1) {
            return 1;
        }
        
        //check in dp matrix
        if(dp[r][c] >= 0) {
            return dp[r][c];
        }
        
        //recursion state
        dp[r][c] = travel(grid, r+1, c, dp) + travel(grid, r, c+1, dp);
        return dp[r][c];
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return travel(obstacleGrid, 0, 0, dp);
    }
};
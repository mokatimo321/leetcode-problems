class Solution {
public:
    
    void solve(vector<vector<int>> &grid, int i, int j, int &cnt) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1) {
            return;
        }
            
        cnt++;
        grid[i][j] = -1;
        
        solve(grid, i-1, j, cnt);
        solve(grid, i, j+1, cnt);
        solve(grid, i+1, j, cnt);
        solve(grid, i, j-1, cnt);
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int res = 0, cnt = 0;
        
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    cnt = 0;
                    solve(grid, i, j, cnt);
                    res = max(res, cnt);
                }
            }
        }
        
        return res;
        
    }
};
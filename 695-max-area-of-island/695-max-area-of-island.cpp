class Solution {
public:
    
    void solve(vector<vector<int>> grid, vector<vector<bool>> &visited, int i, int j, int &cnt) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j] == true) {
            return;
        }
            
        cnt++;
        visited[i][j] = true;
        
        solve(grid, visited, i-1, j, cnt);
        solve(grid, visited, i, j+1, cnt);
        solve(grid, visited, i+1, j, cnt);
        solve(grid, visited, i, j-1, cnt);
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0, cnt = 0;
        
        
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    cnt = 0;
                    solve(grid, visited, i, j, cnt);
                    res = max(res, cnt);
                }
            }
        }
        
        return res;
        
    }
};
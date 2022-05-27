class Solution {
public:
    
    void traverse(vector<vector<int>> &grid, int i, int j, int &fl, int &cnt) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }
        
        if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) {
            fl = 1;
        }
        
        cnt++;
        
        grid[i][j] = -1;
        
        traverse(grid, i-1, j, fl, cnt);
        traverse(grid, i, j+1, fl, cnt);
        traverse(grid, i+1, j, fl, cnt);
        traverse(grid, i, j-1, fl, cnt);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int fl = 0, cnt = 0;
        int res = 0;
        
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    fl = 0, cnt = 0;
                    traverse(grid, i, j, fl, cnt);
                    if(fl == 0) {
                        res += cnt;
                    }
                }
            }
        }
        
        return res;
        
    }
};
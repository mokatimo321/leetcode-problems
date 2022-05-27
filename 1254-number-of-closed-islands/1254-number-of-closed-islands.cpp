class Solution {
public:
    
    void traverse(vector<vector<int>> &grid, int i, int j, int &fl) {
        
        //base case
        if(i <0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0) {
            return;
        }
        
        if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) {
            fl = 1;
        }
        
        
        grid[i][j] = -1;
        
        traverse(grid, i-1, j, fl);
        traverse(grid, i, j+1, fl);
        traverse(grid, i+1, j, fl);
        traverse(grid, i, j-1, fl);
        
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int fl = 0, cnt = 0;
        
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 0) {
                    fl = 0;
                    traverse(grid, i, j, fl);
                    if(fl == 0) {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
        
    }
};
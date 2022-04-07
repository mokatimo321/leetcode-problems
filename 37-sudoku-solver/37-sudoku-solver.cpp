class Solution {
public:
    
    
    bool canPlace(vector<vector<char>> board, int i, int j, char num) {
        
        // int x = i, y = j;
        //row till now
        for(int x = 0;x < 9;x++) {
            if(board[i][x] == num) {
                return false;
            }
        }
        
        //col till now
        for(int x = 0;x<9;x++) {
            if(board[x][j] == num) {
                return false;
            }
        }
        
        //9*9 box
        int x = i - i%3, y = j - j%3;
        for(int p = 0;p<3;p++) {
            for(int q = 0;q<3;q++) {
                if(board[p + x][q + y] == num) {
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    
    bool solve(vector<vector<char>> &board, int i, int j) {
        
        //base case
        if(i == 9) {
            return true;
        }
        
        if(j == 9) {
            return solve(board, i+1, 0);
        }
        
        if(board[i][j] != '.') {
            return solve(board, i, j+1);
        }
        
        //recur case
        for(char x = '1';x <= '9';x++) {
            if(canPlace(board, i, j, x)) {
                board[i][j] = x;
                bool further = solve(board, i, j + 1);
                if(further) {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        
        return false;
        
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
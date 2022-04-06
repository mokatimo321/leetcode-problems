class Solution {
public:
    
    
    bool canPlace(vector<string> board, int i, int j, int n) {
        
        //to check for left diag
        int x = i, y = j;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q') {
                return false;
            }
            x--, y--;
        }
        
        //to check for right diag
        x = i, y = j;
        while(x >= 0 && y <= n-1) {
            if(board[x][y] == 'Q') {
                return false;
            }
            x--, y++;
        }
        
        //to check for col
        for(x = 0; x < i; x++) {
            if(board[x][j] == 'Q') {
                return false;
            }
        }
        
        return true;
        
    }
    
    void solve(vector<vector<string>> &result, vector<string> board, int sz, int i) {
        
        //base case
        if(i == sz) {
            result.push_back(board);
            return;
        }
        
        
        //recur case
        for(int j = 0;j<sz;j++) {
            if(canPlace(board, i, j, sz)) {
                board[i][j] = 'Q';
                solve(result, board, sz, i + 1);
                board[i][j] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        string s = "";
        for(int i = 0;i<n;i++) {
            s += ".";
        }
        for(int i = 0;i<n;i++) {
            board.push_back(s);
        }
        solve(result, board, n, 0);
        return result;
    }
};
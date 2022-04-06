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
    
    void solve(int &cnt, vector<string> board, int sz, int i) {
        
        //base case
        if(i == sz) {
            cnt++;
            return;
        }
        
        
        //recur case
        for(int j = 0;j<sz;j++) {
            if(canPlace(board, i, j, sz)) {
                board[i][j] = 'Q';
                solve(cnt, board, sz, i + 1);
                board[i][j] = '.';
            }
        }
        
    }
    
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string> board;
        string s = "";
        for(int i = 0;i<n;i++) {
            s += ".";
        }
        for(int i = 0;i<n;i++) {
            board.push_back(s);
        }
        solve(cnt, board, n, 0);
        return cnt;
    }
};
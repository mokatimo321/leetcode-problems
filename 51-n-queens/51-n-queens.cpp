class Solution {
public:
    
    bool validate(vector<string> grid, int r, int c, int n) {
        //it is gonna return whether we can place the queen at this position or not
        
        //for vertical case
        int i = r, j = c;
        while(i >= 0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--;
        }
        
        //for left diagonal case
        i = r, j = c;
        while(i >= 0 && j >= 0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--, j--;
        }
        
        //for right diagonal case
        i = r, j = c;
        while(i >= 0 && j < n) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--, j++;
        }
        
        //this position is valid
        return true;
    }
    
    
    void generate(int n, vector<vector<string>> &result, vector<string> fill, int index) {
        
        //base case
        if(index == n) {
            result.push_back(fill);
            return;
        }
        
        
        //recur case
        for(int i = 0;i<n;i++) {
            if(validate(fill, index, i, n)) {
                fill[index][i] = 'Q';
                generate(n, result, fill, index+1);
                fill[index][i] = '.';
            }
        }
        
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> fill;
        for(int i = 0;i<n;i++) {
            string s = "";
            for(int i = 0;i<n;i++) {
                s += ".";
            }
            fill.push_back(s);
        }
        int index = 0;
        generate(n, result, fill, index);
        return result;
    }
};
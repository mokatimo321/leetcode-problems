class Solution {
public:
    int minCost(string clr, vector<int>& nt) {
        
        char col = clr[0];
        int ans = 0;
        int temp = nt[0], mx = nt[0], fl = 0;
        for(int i = 1;i<clr.length();i++) {
            if(clr[i] == col) {
                temp += nt[i];
                mx = max(mx, nt[i]);
                fl = 1;
            }
            else {
                if(fl == 1) {
                    ans += (temp - mx);
                    fl = 0;
                }
                temp = nt[i];
                col = clr[i];
                mx = nt[i];
            }
        }
        
        if(fl == 1) {
            ans += (temp - mx);
            fl = 0;
        }
        
        return ans;   
    }
};
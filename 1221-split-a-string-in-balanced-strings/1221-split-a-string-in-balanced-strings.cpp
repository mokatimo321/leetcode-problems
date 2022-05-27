class Solution {
public:
    int balancedStringSplit(string s) {
        
        int lc = 0, rc = 0;
        int ans = 0;
        
        if(s[0] == 'L') {
            lc++;
        }
        else {
            rc++;
        }
        
        for(int i = 1;i<s.length();i++) {
            if(s[i] == 'L') {
                lc++;
            }
            else {
                rc++;
            }
            if(lc == rc) {
                ans++;
                lc = 0, rc = 0;
            }
        }
        return ans;
    }
};
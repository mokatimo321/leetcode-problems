class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) {
            return s;
        }
        
        vector<string> res(numRows, "");
        
        int track = 0, fl = -1;
        
        for(int i = 0;i<s.length();i++) {
            if(i%(numRows - 1) == 0) {
                fl *= -1;
            }
            res[track] += s[i];
            track += fl;
        }
        
        string ans = "";
        
        for(int i = 0;i<res.size();i++) {
            ans += res[i];
        }
            
        return ans;
    }
};
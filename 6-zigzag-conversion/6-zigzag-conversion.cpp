class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) {
            return s;
        }
        
        vector<string> res(numRows, "");
        
        int track = 0, fl = 1;
        
        res[track] += s[0];
        track++;
        
        for(int i = 1;i<s.length();i++) {
            res[track] += s[i];
            if(track == 0 || track == numRows-1) {
                fl *= -1;
            }
            if(fl == 1) {
                track++;
            }
            else {
                track--;
            }
        }
        
        string ans = "";
        
        for(int i = 0;i<res.size();i++) {
            ans += res[i];
        }
            
        return ans;
    }
};
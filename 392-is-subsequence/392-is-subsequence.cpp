class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x = 0;
        for(int i = 0;i<t.length();i++) {
            if(x == s.length()) {
                return true;
            }
            if(t[i] == s[x]) {
                x++;
            }
        }
        return x == s.length() ? true : false;
    }
};
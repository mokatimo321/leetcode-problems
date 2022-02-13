class Solution {
public:
    string longestPalindrome(string s) {
        string m = s;
        reverse(m.begin(), m.end());
        if(s == m) {
            return s;
        }
        vector<vector<bool>> mo(s.length(), vector<bool> (s.length(), false));
        int n = s.length();
        int j = 0;
        string mx = "";
        while(n > 0) {
            int i = 0;
            int temp = j;
            while(j < s.length()) {
                if(i == j) {
                    mo[i][j] = true;
                    mx = s[i];
                }
                else if(j - i == 1 && s[i] == s[j]) {
                    mo[i][j] = true;
                    mx = s.substr(i, 2);
                }
                else if(s[i] == s[j] && mo[i+1][j-1] == true) {
                    mo[i][j] = true;
                    mx = s.substr(i, (j-i)+1);
                }
                j++;
                i++;
            }
            j = temp + 1;
            n--;
        }
        return mx;
    }
};
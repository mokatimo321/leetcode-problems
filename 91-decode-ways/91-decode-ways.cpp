class Solution {
public:
    
    int decode(string s, int index, vector<int> &dp) {
        
        if(index == s.length()) {
            return 1;
        }
        
        if(s[index] == '0') {
            return 0;
        }
        
        if(dp[index] > -1) {
            return dp[index];
        }
        
        int single_digit = decode(s, index+1, dp);
        int double_digit = 0;
        
        if(index < s.length() - 1 && (s[index] == '1' || (s[index] == '2' && s[index+1] < '7'))) {
            double_digit = decode(s, index+2, dp);
        }
        
        dp[index] = single_digit + double_digit;
        return dp[index];
        
    }
    
    
    int numDecodings(string s) {
        
        vector<int> dp(s.length(), -1);
        return decode(s, 0, dp);
        
    }
};
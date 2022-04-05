class Solution {
public:
    
    void generate(string s, string ans, int index, int sz, vector<string> &result) {
        
        //base
        if(index == sz) {
            result.push_back(ans);
            return;
        }
        
        //recur case
        //if case is changed
        if(int(s[index]) > 57) {
            if(int(s[index]) > 92) {
                generate(s, ans + char((int(s[index]) - 32)), index + 1, sz, result);
            }
            else {
                generate(s, ans + char((int(s[index]) + 32)), index + 1, sz, result);
            }
        }
        
        //if case is unchanged
        generate(s, ans + s[index], index + 1, sz, result);
        
    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        int sz = s.length();
        generate(s, "", 0, sz, result);
        return result;
    }
};
class Solution {
public:
    
    
    
    void mo(string digits, string s, int index, int sz, vector<string> combi, vector<string> &result) {
        
        //base case
        if(index == sz) {
            result.push_back(s);
            return;
        }
        
        int temp = (int(digits[index]) - 48) - 2;
        
        //recur call
        for(int i = 0;i<combi[temp].length();i++) {
            mo(digits, s + combi[temp][i], index+1, sz, combi, result);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return {};
        }
        
        vector<string> combi = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        
        mo(digits, "", 0, digits.length(), combi, result);
        return result;
    }
};
class Solution {
public:
    
    vector<string> combi = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    
    void mo(string digits, string s, int index, int sz) {
        
        //base case
        if(index == sz) {
            result.push_back(s);
            return;
        }
        
        //recur call
        for(int i = 0;i<combi[(int(digits[index]) - 48) - 2].length();i++) {
            mo(digits, s + combi[(int(digits[index]) - 48) - 2][i], index+1, sz);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return {};
        }
        mo(digits, "", 0, digits.length());
        return result;
    }
};
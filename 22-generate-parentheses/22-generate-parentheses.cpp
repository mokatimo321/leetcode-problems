class Solution {
public:
    
    void generate(int n, string s, vector<string> &result, int count, int open) {
        
        //base case
        if(s.length() == 2*n) {
            result.push_back(s);
            return;
        }
        
        
        
        //add open bracket
        if(count < n) {
            s += "(";
            generate(n, s, result, count+1, open+1);
            s.pop_back();
        }
        
        
        //to add close bracket
        if(open > 0) {
            s += ")";
            generate(n, s, result, count, open-1);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, "", result, 0, 0);
        return result;
    }
};
class Solution {
public:
    
    //vector<string> result;
    
    void generate(vector<string> &result,string s,int index, int n, int fl, int cnt) {
        
        if(index == 2*n) {
            result.push_back(s);
        }
        
        //putting an opening bracket
        if(cnt < n) {
            generate(result, s + "(", index + 1, n, fl + 1, cnt + 1);
        }
        
        //putting a closing bracket
        if(fl > 0) {
            generate(result, s + ")", index + 1, n, fl - 1, cnt);
        }
        
    } 
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", 0, n, 0, 0);
        return result;
    }
};
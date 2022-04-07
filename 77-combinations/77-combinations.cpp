class Solution {
public:
    
    
    void solve(int n, vector<int> sub, vector<vector<int>> &result, int temp, int k) {
        
        //base case
        if(sub.size() == k) {
            result.push_back(sub);
            return;
        }
        
        
        //recur case
        for(int i = 1; i <= n ;i++) {
            if(i > temp) {
                sub.push_back(i);
                solve(n, sub, result, i, k);
                sub.pop_back();
            }
        }
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        //vector<int> sub(k, 0);
        solve(n, {}, result, 0, k);
        return result;
    }
};
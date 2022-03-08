class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if(numRows == 1) {
            return res;
        }
        res.push_back({1, 1});
        if(numRows == 2) {
            return res;
        }
        for(int i = 2;i<numRows;i++) {
            vector<int> mo;
            mo.push_back(1);
            for(int j = 1;j<res[i-1].size();j++) {
                mo.push_back(res[i-1][j] + res[i-1][j-1]);
            }
            mo.push_back(1);
            res.push_back(mo);
        }
        return res;
    }
};
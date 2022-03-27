class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, vector<int>> mp;
        for(int i = 0;i<mat.size();i++) {
            int cnt = 0;
            for(int j = 0;j<mat[0].size();j++) {
                if(mat[i][j] == 1) {
                    cnt++;
                }
            }
            mp[cnt].push_back(i);
        }
        vector<int> mo;
        map<int, vector<int>> :: iterator itr;
        for(itr = mp.begin();itr != mp.end();itr++) {
            for(int i = 0;i<itr->second.size();i++) {
                mo.push_back(itr->second[i]);
                k--;
                if(k == 0) {
                    return mo;
                }
            }
        }
        return mo;
    }
};
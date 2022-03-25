class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cst) {
        map<int, vector<int>> mp;
        for(int i = 0;i<cst.size();i++) {
            mp[cst[i][1] - cst[i][0]].push_back(i);
        }
        map<int, vector<int>> :: iterator itr;
        int sm = 0;
        int fl = 0;
        int cnt = cst.size();
        for(itr = mp.begin();itr != mp.end();itr++) {
            for(int i = 0;i<itr->second.size();i++) {
                if(fl == 0) {
                    sm += cst[itr->second[i]][1];
                    cnt--;
                }
                else {
                    sm += cst[itr->second[i]][0];
                    cnt--;
                }
                if(cnt == cst.size()/2) {
                    fl = 1;
                }
            }
        }
        return sm;
    }
};
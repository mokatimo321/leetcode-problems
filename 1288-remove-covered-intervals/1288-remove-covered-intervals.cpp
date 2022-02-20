class Solution {
public:
        int removeCoveredIntervals(vector<vector<int>>& inter) {
        int cnt = 0;
        int i = -1, j = -1;
        sort(inter.begin(), inter.end());
        for (auto x : inter) {
            if (x[0] > i && x[1] > j) {
                i = x[0];
                ++cnt;
            }
            j = max(j, x[1]);
        }
        return cnt;
    }
};
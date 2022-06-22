class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cst) {
        
        double waiting_time = 0;
        int last_time = cst[0][0];
        for(int i = 0;i<cst.size();i++) {
            if(last_time < cst[i][0]) {
                last_time = cst[i][0] + cst[i][1];
            }
            else {
                last_time += cst[i][1];
            }
            waiting_time += last_time - cst[i][0];
        }
        waiting_time /= cst.size();
        return waiting_time;
    }
};
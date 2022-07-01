class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(int i = 0;i<boxTypes.size();i++) {
            int temp = 0;
            temp = boxTypes[i][0];
            boxTypes[i][0] = boxTypes[i][1];
            boxTypes[i][1] = temp;
        }
        sort(boxTypes.begin(), boxTypes.end());
        reverse(boxTypes.begin(), boxTypes.end());
        int cnt = 0, res = 0;
        int i = 0;
        while(cnt <= truckSize && i < boxTypes.size()) {
            res += boxTypes[i][0]*boxTypes[i][1];
            cnt += boxTypes[i][1];
            if(cnt > truckSize) {
                res -= boxTypes[i][0]*boxTypes[i][1];
                cnt -= boxTypes[i][1];
                res += (truckSize - cnt)*boxTypes[i][0];
                break;
            }
            i++;
        }
        return res;
    }
};
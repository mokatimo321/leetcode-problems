class Solution {
public:
    int brokenCalc(int st, int tar) {
        int cnt = 0;
        while(tar != st) {
            if(tar < st) {
                cnt += st - tar;
                tar = st;
            }
            else if(tar%2 != 0) {
                cnt++;
                tar += 1;
            }
            else {
                tar /= 2;
                cnt++;
            }
        }
        return cnt;
    }
};
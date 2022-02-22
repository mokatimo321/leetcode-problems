class Solution {
public:
    int titleToNumber(string ct) {
        int res = 0;
        for(int i = 0;i<ct.length();i++) {
            res = res*26 + (int(ct[i]) - 64);
        }
        return res;
    }
};
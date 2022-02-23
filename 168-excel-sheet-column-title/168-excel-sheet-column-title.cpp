class Solution {
public:
    string convertToTitle(int cn) {
        string res = "";
        while(cn) {
            int temp = cn%26;
            if(temp == 0) {
                temp = 26;
            }
            res += char(temp + 64);
            cn -= temp;
            cn /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
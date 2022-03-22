class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        while(n) {
            int temp = 1;
            while(float(k-temp)/(float)(n-1) > 26) {
                temp++;
            }
            k -= temp;
            res += char(96 + temp);
            n--;
        }
        return res;
    }
};
class Solution {
public:
    
    int countNumbersWithUniqueDigits(int n) {
        vector<int> res;
        res.push_back(1);
        if(n == 0) {
            return res[0];
        }
        int x = 1;
        while(x <= n) {
            int temp = 1, mul = 9;
            temp *= mul;
            for(int i = 1;i<x;i++) {
                temp *= mul;
                mul--;
            }
            res.push_back(res[res.size() - 1] + temp);
            x++;
        }
        return res[res.size() - 1];
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 1;i<=n;i++) {
            res[i] = 1 + res[i&(i-1)];
        }
        return res;
    }
};


class Solution {
public:
    int totalMoney(int n) {
        int sm = 0;
        vector<int> mo(7, 0);
        int c = 1;
        for(int i = 0;i<mo.size();i++) {
            mo[i] = c;
            c++;
        }
        for(int i = 0;i<n;i++) {
            sm += mo[i%7];
            mo[i%7]++;
        }
        return sm;
    }
};
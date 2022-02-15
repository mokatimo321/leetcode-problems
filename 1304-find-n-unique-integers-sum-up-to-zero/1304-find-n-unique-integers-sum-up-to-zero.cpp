class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> m;
        if(n == 1) {
            m.push_back(0);
            return m;
        }
        int cnt = n;
        if(cnt%2 != 0) {
            m.push_back(n/2);
            m.push_back((n/2)+1);
            m.push_back(n*-1);
            cnt -= 3;
        }
        while(cnt) {
            n += 1;
            m.push_back(n);
            m.push_back(n*-1);
            cnt -= 2;
        }
        return m;
    }
};
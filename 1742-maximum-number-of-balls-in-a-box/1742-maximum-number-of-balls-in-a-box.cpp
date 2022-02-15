class Solution {
public:
    
    int sm(int n) {
        int sum = 0;
        while(n) {
            int dig = n%10;
            sum += dig;
            n /= 10;
        }
        return sum;
    }
    
    int countBalls(int l, int h) {
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for(int i = l;i<=h;i++) {
            int temp = sm(i);
            mp[temp]++;
            mx = max(mx, mp[temp]);
        }
        return mx;
    }
};
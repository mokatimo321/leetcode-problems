class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, pair<int, int>> mp;
        mp[0] = {1, 0};
        //first -> frequency, second -> index
        int sm = 0, rem = 0, cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            sm += nums[i];
            rem = sm%k;
            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem].first;
                if(i - mp[rem].second == 0) {
                    cnt--;
                }
            }
            mp[rem].first++;
            mp[rem].second = i+1;
        }
        return cnt;
    }
};
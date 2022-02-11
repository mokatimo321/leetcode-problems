class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int tar) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sm = 0, cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            sm += nums[i];
            if(mp.find(sm - tar) != mp.end()) {
                cnt += mp[sm - tar];
            }
            mp[sm]++;
        }
        return cnt;
    }
};
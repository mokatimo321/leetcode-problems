class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sm = 0, cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            sm += nums[i];
            if(mp.count(sm-k)) {
                cnt += mp[sm - k];
            }
            mp[sm]++;
        }
        return cnt;
    }
};
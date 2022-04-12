class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> m;
        for(int i = 0;i<nums.size();i++) {
            if(mp.find(nums[i]) != mp.end()) {
                m.push_back(mp[nums[i]]);
                m.push_back(i);
            }
            else {
                mp[target - nums[i]] = i;
            }
        }   
        return m;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int current_sum = 0 ,counter = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        
        for(int i = 0;i<nums.size();i++) {
            current_sum += nums[i];
            int find = current_sum - k;
            if(mp.find(find) != mp.end()) {
                counter += mp[find];
            }
            mp[current_sum]++;
        }
        
        return counter;
        
    }
};
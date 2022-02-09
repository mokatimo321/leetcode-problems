class Solution {
public:
    
    int mo(vector<vector<int>> nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 0;i<nums.size();i++) {
            if(i == 0) {
                dp[i] = nums[i][1];
            }
            else if(i == 1) {
                if(nums[i][0] - nums[i-1][0] == 1) {
                    dp[i] = max(nums[i][1], nums[i-1][1]);
                }
                else {
                    dp[i] = dp[i-1] + nums[i][1];
                }
            }
            else if(nums[i][0] - 1 == nums[i-1][0]) {
                if(nums[i][1] + dp[i-2] > dp[i-1]) {
                    dp[i] = nums[i][1] + dp[i-2];
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
            else {
                dp[i] = dp[i-1] + nums[i][1];
            }
        }
        return dp[nums.size() - 1];
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        vector<vector<int>> momo;
        for(auto x : mp) {
            momo.push_back({x.first, x.first*x.second});
        }
        sort(momo.begin(), momo.end());
        int res = mo(momo);
        return res;
    }
};
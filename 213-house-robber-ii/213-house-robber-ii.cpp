class Solution {
public:
    
    int mo(vector<int> nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 0;i<nums.size();i++) {
            if(i == 0) {
                dp[i] = nums[0];
            }
            else if(i == 1) {
                dp[i] = max(nums[0], nums[1]);
            }
            else {
                if(nums[i] + dp[i-2] > dp[i-1]) {
                    dp[i] = nums[i] + dp[i-2];
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[nums.size() - 1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<int> a;
        vector<int> b;
        int i = 0;
        a.push_back(nums[i]);
        i++;
        for(i;i<nums.size()- 1;i++) {
            a.push_back(nums[i]);
            b.push_back(nums[i]);
        }
        b.push_back(nums[nums.size() - 1]);
        return max(mo(a), mo(b));
    }
};
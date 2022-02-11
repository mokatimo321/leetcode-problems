class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0, best_sum = nums[0];
        for(int i = 0;i<nums.size();i++) {
            curr_sum += nums[i];
            curr_sum = max(curr_sum, nums[i]);
            best_sum = max(best_sum, curr_sum);
            cout<<best_sum<<endl;
        }
        return best_sum;
    }
};
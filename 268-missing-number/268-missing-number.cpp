class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //keep a track of total sum to avoid traversing the array at last to find the answer
        int total_sum = (nums.size()*(nums.size() + 1))/2;
        
        for(int i = 0;i<nums.size();i++) {
            total_sum -= nums[i];
        }
        
        return total_sum;
        
    }
};
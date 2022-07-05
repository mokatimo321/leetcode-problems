class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        //2 pass solution
        int max_prof = 0;
        
        //cummulative sell
        for(int i = 1;i<nums.size();i++) {
            if(nums[i] > nums[i-1]) {
                max_prof += nums[i];
            }
        }
        
        //cummulative buy
        for(int i = 0;i<nums.size() - 1;i++) {
            if(nums[i] < nums[i+1]) {
                max_prof -= nums[i];
            }
        }
        
        return max_prof;
        
    }
};
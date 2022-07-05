class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        //single pass solution
        int buy_price = nums[0], sell_price = nums[0];
        int max_prof = 0;
        
        
        for(int i = 1;i<nums.size();i++) {
            if(nums[i] > sell_price) {
                sell_price = nums[i];
            }
            else {
                max_prof += sell_price - buy_price;
                buy_price = nums[i];
                sell_price = nums[i];
            }
        }
        
        return max_prof + (sell_price - buy_price);
        
    }
};
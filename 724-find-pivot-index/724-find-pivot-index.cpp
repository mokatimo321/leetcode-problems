class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        //find the sum of the array
        int sm = accumulate(nums.begin(), nums.end(), 0);
        int curr_sum = 0, last_sum = 0;
        
        for(int i = 0;i<nums.size();i++) {
            //curr_sum += nums[i];
            last_sum = sm - curr_sum - nums[i];
            //cout<<curr_sum<<"----"<<last_sum<<endl;
            if(curr_sum == last_sum) {
                return i;
            }
            curr_sum += nums[i];
        }
        
        return -1;
        
    }
};
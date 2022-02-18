class Solution {
public:
       
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 0;
        }
        
        int last = nums[0];
        int j = 1;

        for(int i = 1;i<nums.size();i++) {
            if(nums[i] != last) {
                nums[j] = nums[i];
                last = nums[j];
                j++;
            }
        }
        
        return j;
    }
};
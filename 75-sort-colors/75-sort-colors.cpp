class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, middle = 0, right = nums.size() - 1;
        while(middle <= right) {
            if(nums[middle] == 0) {
                nums[middle] = nums[left];
                nums[left] = 0;
                left++;
                middle++;
            }
            else if(nums[middle] == 1) {
                middle++;
            }
            else {
                nums[middle] = nums[right];
                nums[right] = 2;
                right--;
            }
        }
    }
};
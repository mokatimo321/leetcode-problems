class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int left = 0, mid = 0, right = nums.size() - 1;
        
        while(right >= mid) {
            if(nums[mid] == 0) {
                int temp = nums[left];
                nums[left] = nums[mid];
                nums[mid] = temp;
                left++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                int temp = nums[right];
                nums[right] = nums[mid];
                nums[mid] = temp;
                right--;
            }
        }
    }
};
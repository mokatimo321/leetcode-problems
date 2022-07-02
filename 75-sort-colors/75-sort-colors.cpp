class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //keep 3 pointers low, mid & high
        int low = 0, mid = 0, high = nums.size() - 1;
        
        //traverse through the array
        while(high >= mid) {
            
            if(nums[mid] == 0) {
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }
            
            
        }
        
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        int j = nums.size() - 1;
        
        int c= 0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != val) {
                c++;
            }
        }
        
        while(i < j) {
            if(nums[j] == val) {
                //c++;
                j--;
            }
            if(nums[i] != val) {
                i++;
            }
            if(nums[i] == val && nums[j] != val && i < j) {
                //c++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        
        return c;
        
    }
};
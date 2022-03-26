class Solution {
public:
    
    int bs(vector<int> nums, int l, int r, int target) {
        
        if(r >= l) {
            
            int mid = l + (r - l)/2;
            
            if(nums[mid] == target) {
                return mid;
            }
            
            if(nums[mid] > target) {
                return bs(nums, l, mid - 1, target);
            }
            
            else {
                return bs(nums, mid + 1, r, target);
            }
        }
        
        return -1;
        
        
    }
    
    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size() - 1, target);
    }
};
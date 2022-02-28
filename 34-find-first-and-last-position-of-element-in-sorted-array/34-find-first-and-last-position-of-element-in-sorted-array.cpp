class Solution {
public:
    
    int binarySearchFirst(int low, int high, vector<int> nums, int target) {
        int mid = low + (high - low)/2;
        while(high >= low) {
            if(nums[mid] == target) {
                if(mid == 0 || nums[mid - 1] != target) {
                    return mid;
                }
                return binarySearchFirst(low, mid - 1, nums, target);
            }
            else if(nums[mid] > target) {
                return binarySearchFirst(low, mid - 1, nums, target);
            }
            return binarySearchFirst(mid + 1, high, nums, target);
        }
        return -1;
    }
    
    
    int binarySearchLast(int low, int high, vector<int> nums, int target) {
        int mid = low + (high - low)/2;
        while(high >= low) {
            if(nums[mid] == target) {
                if(mid == nums.size() - 1 || nums[mid+1] != target) {
                    return mid;
                }
                return binarySearchLast(mid+1, high, nums, target);
            }
            else if(nums[mid] > target) {
                return binarySearchLast(low, mid - 1, nums, target);
            }
            return binarySearchLast(mid + 1, high, nums, target);
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return {binarySearchFirst(low, high, nums, target), binarySearchLast(low, high, nums, target)};
    }
};
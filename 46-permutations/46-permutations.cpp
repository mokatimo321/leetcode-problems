class Solution {
public:
    
    void permute(vector<int> nums, vector<vector<int>> &result, vector<int> fill, vector<int> &placed, int index) {
        
        //base case
        if(index == nums.size()) {
            result.push_back(fill);
        }
        
        
        //loop
        for(int i = 0;i<nums.size();i++) {
            if(placed[nums[i]+10] == 0) {
                //add the element to the fill array
                fill[index] = nums[i];
                placed[nums[i] + 10] = 1;
                permute(nums, result, fill, placed, index+1);
                placed[nums[i] + 10] = 0;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> placed(21, 0);
        vector<int> fill(nums.size(), 0);
        permute(nums, result, fill, placed, 0);
        return result;
    }
};
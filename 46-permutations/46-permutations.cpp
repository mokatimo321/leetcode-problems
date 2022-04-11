class Solution {
public:
    
    void solve(vector<int> nums, vector<vector<int>> &result, int index) {
        
        //base case
        if(index == nums.size()) {
            result.push_back(nums);
        }
        
        
        //recur case
        for(int i = index;i<nums.size();i++) {
            swap(nums[index], nums[i]);
            solve(nums, result, index + 1);
            swap(nums[index], nums[i]);
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, result, 0);
        return result;
    }
};
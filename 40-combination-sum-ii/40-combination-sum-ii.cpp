class Solution {
public:
    
    void combine(vector<int> nums, int index, int curr_sum, vector<vector<int>> &result, vector<int> fill) {
        
        //base case
        if(curr_sum <= 0 || index == nums.size()) {
            if(curr_sum == 0) {
                result.push_back(fill);
            }
            return;
        }
        
        
        //recur case
        for(int i = index;i<nums.size();i++) {
            if(i > index && nums[i] == nums[i-1]) {
                continue;
            }
            fill.push_back(nums[i]);
            combine(nums, i+1, curr_sum - nums[i], result, fill);
            fill.pop_back();
        }
        
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        combine(nums, 0, target, result, {});
        return result;
    }
};
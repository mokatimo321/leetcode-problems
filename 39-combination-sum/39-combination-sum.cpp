class Solution {
public:
    
    void combine(vector<int> nums, int index, int current_sum, vector<vector<int>> &result, vector<int> fill) {
        
        //base case
        if(current_sum <= 0 || index == nums.size()) {
            if(fill.size() > 0 && current_sum == 0) {
                result.push_back(fill);
            }
            return;
        }
        
        
        //recur case
        for(int i = index;i<nums.size();i++) {
            fill.push_back(nums[i]);
            combine(nums, index, current_sum - nums[i], result, fill);
            index++;
            fill.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        combine(nums, 0, target, result, {});
        return result;
    }
};
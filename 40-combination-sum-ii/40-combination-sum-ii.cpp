class Solution {
public:
    
    void combine(vector<int> nums, vector<vector<int>> &result, vector<int> fill, int index, int curr_sum) {
        
        if(curr_sum == 0) {
            result.push_back(fill);
            return;
        }
        
        for(int i = index;i<nums.size();i++) {
            if(i > index && nums[i] == nums[i-1]) {
                continue;
            }
            if(curr_sum < 0) {
                break;
            }
            fill.push_back(nums[i]);
            combine(nums, result, fill, i+1, curr_sum - nums[i]);
            fill.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        combine(nums, result, {}, 0, target);
        return result;
    }
};
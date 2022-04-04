class Solution {
public:
    
    void generate(vector<vector<int>> &result, vector<int> nums, vector<int> subsets, int index) {
        result.push_back(subsets);
        for(int i = index;i<nums.size();i++) {
            subsets.push_back(nums[i]);
            generate(result, nums, subsets, i + 1);
            subsets.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        generate(result, nums, {}, 0);
        return result;
    }
};
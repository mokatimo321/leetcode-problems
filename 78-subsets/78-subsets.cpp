class Solution {
public:
    
    void generate(vector<int> nums, int index, vector<vector<int>> &result, vector<int> fill) {
        result.push_back(fill);
        for(int i = index;i<nums.size();i++) {
            //number is taken
            fill.push_back(nums[i]);
            generate(nums, i+1, result, fill);
            //if the number is not taken
            fill.pop_back();
        }
        return;
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        generate(nums, 0, result, {});
        return result;
    }
};
class Solution {
public:
    
    void generate(vector<int> nums, vector<vector<int>> &result, vector<int> fill, int index) {
        
        result.push_back(fill);
        for(int i = index;i<nums.size();i++) {
            if(i > index && nums[i] == nums[i-1]) {
                continue;
            }
            //if the number is taken
            fill.push_back(nums[i]);
            generate(nums, result, fill, i+1);
            //if the number is not taken
            fill.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        generate(nums, result, {}, 0);
        return result;
    }
};
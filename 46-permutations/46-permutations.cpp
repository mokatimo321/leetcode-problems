class Solution {
public:
    
    
    void generate(vector<int> nums, vector<vector<int>> &result, vector<int> sub, vector<int> memo, int index, int sz) {
        //base case
        if(index == sz) {
            result.push_back(sub);
            return;
        }
        //recur case
        for(int i = 0;i<nums.size();i++) {
            if(memo[i] == 0) {
                sub[index] = nums[i];
                memo[i] = 1;
                generate(nums, result, sub, memo, index + 1, sz);
                memo[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {    
        vector<vector<int>> result;
        vector<int> sub(nums.size(), 0);
        vector<int> memo(nums.size(), 0);
        int sz = nums.size();
        generate(nums, result, sub, memo, 0, sz);
        return result;
    }
    
};
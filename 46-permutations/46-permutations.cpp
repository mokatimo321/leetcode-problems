class Solution {
public:
    
    void solve(vector<int> sub, vector<vector<int>> &result, vector<int> memo, int index, int sz, vector<int> nums) {
        
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
                solve(sub, result, memo, index + 1, sz, nums);
                memo[i] = 0;
            }
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub(nums.size(), 0), memo(nums.size(), 0);
        int sz = nums.size();
        solve(sub, result, memo, 0, sz, nums);
        return result;
    }
};
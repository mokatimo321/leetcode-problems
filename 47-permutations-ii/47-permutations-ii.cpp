class Solution {
public:
    
    void solve(vector<vector<int>> &result, vector<int> nums, int index) {
        
        //base case
        if(index == nums.size()) {
            result.push_back(nums);
            //return;
        }
        
        //recur case
        unordered_set<int> st;
        for(int i = index;i<nums.size();i++) {
            if(st.count(nums[i]) > 0) {
                continue;
            }
            st.insert(nums[i]);
            swap(nums[index], nums[i]);
            solve(result, nums, index + 1);
            swap(nums[index], nums[i]);
        }
        
        
    }
    
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        solve(result, nums, 0);
        return result;
    }
};
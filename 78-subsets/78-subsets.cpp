class Solution {
public:
    
    void mo(vector<int> nums, vector<vector<int>> &ans, vector<int> &subset, int index) {
        
        ans.push_back(subset);
        
        for(int i = index;i<nums.size();i++) {
            
            subset.push_back(nums[i]);
            mo(nums, ans, subset, i+1);
            
            subset.pop_back();
            
        }
        
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        mo(nums, ans, subset, 0);
        return ans;
    }
};
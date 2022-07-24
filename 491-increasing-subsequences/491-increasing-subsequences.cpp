class Solution {
public:
    
    void get_sub(vector<int> nums, int index, int last_num, vector<int> fill, set<vector<int>> &result, int cnt) {
        
        if(cnt >= 2) {
            result.insert(fill);
        }
        
        if(index == nums.size()) {
            return;
        }
        
        for(int i = index;i<nums.size();i++) {
            if(last_num <= nums[i]) {
                fill.push_back(nums[i]);
                get_sub(nums, i+1, nums[i], fill, result, cnt+1);
                fill.pop_back();
            }
        }
        
    }
    
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        
        set<vector<int>> st;
        get_sub(nums, 0, INT_MIN, {}, st, 0);
        vector<vector<int>> result(st.begin(), st.end());
        return result;
        
    }
};
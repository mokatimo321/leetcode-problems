class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> mo(nums.size(), 0);
        for(int i = 0;i<nums.size();i++) {
            mo[i] = nums[nums[i]];
        }
        return mo;
    }
};
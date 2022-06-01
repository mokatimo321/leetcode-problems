class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> m;
        int sm = 0;
        for(int i = 0;i<nums.size();i++) {
            sm += nums[i];
            m.push_back(sm);
        }
        return m;
    }
};
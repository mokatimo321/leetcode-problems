class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> mo;
        int cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == 0) {
                cnt++;
            }
            else {
                mo.push_back(nums[i]);
            }
        }
        for(int i = 0;i<cnt;i++) {
            mo.push_back(0);
        }
        nums = mo;
    }
};
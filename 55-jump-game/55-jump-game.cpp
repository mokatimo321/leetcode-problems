class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = nums.size() - 1;
        for(int i = nums.size() - 1;i>=0;i--) {
            if(i + nums[i] >= max_index) {
                max_index = i;
            }
        }
        return max_index == 0 ? true : false;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int possible_index = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i + nums[i] >= possible_index) {
                possible_index = i;
            }
        }
        return possible_index == 0 ? true : false;
    }
};
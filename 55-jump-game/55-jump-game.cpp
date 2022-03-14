class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = nums.size() - 1;
        for(int i = nums.size() - 1;i>=0;i--) {
            if(i + nums[i] >= max_reach) {
                max_reach = i;
            }
        }
        return max_reach == 0 ? true : false;
    }
};
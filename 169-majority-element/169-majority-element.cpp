class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int cnt = 1;
        for(int i = 1;i<nums.size();i++) {
            if(nums[i] == maj) {
                cnt++;
            }
            else if(cnt == 0) {
                cnt = 1;
                maj = nums[i];
            }
            else {
                cnt--;
            }
        }
        return maj;
    }
};
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> mo = nums;
        sort(nums.begin(), nums.end());
        vector<int> temp(500, 0);
        int val = nums[0], cnt = 0;
        
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == val) {
                cnt++;
            }
            else {
                temp[nums[i]] = cnt;
                val = nums[i];
                cnt++;
            }
        }
        
        for(int i = 0;i<mo.size();i++) {
            mo[i] = temp[mo[i]];
        }
        
        return mo;
        
    }
};
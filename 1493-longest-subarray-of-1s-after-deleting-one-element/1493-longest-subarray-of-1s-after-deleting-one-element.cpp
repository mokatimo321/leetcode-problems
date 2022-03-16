class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        vector<int> memo(nums.size(), 0);
        int cnt = 0, max_len = INT_MIN, sz = nums.size();
        
        for(int i = nums.size() - 1;i>=0;i--) {
            if(nums[i] == 1) {
                cnt++;
            }    
            else {
                cnt = 0;
            }
            memo[i] = cnt;
        }
        
        cnt = 0;
        
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == 1) {
                cnt++;
            }
            else {
                if(i != nums.size() - 1) {
                    max_len = max(max_len, cnt + memo[i+1]);
                    cnt = 0;
                }
                else {
                    max_len = max(max_len, cnt);
                }
            }
        }
        
        return cnt == sz ? cnt - 1 : max_len;
        
    }
};
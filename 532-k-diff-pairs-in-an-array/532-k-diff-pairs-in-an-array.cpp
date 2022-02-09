class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return 0;
        }
        int i = 0;
        int j = 1;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        while(j < nums.size()) {
            if(i == j || nums[j] - nums[i] < k) {
                j++;
            }
            else if(nums[j] - nums[i] >= k) {
                if(nums[j] - nums[i] == k) {
                    cnt++;
                    int second = nums[j];
                    while(nums[j] == second) {
                        j++;
                        if(j == nums.size()) {
                            return cnt;
                        }
                    }
                }
                int first = nums[i];
                while(nums[i] == first) {
                    i++;
                }
            }
        }
        return cnt;
    }
};
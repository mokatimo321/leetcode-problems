class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int start = 1, end = 1;
        int max_prod = INT_MIN;
        int sz = nums.size();
        for(int i = 0;i<nums.size();i++) {
            start *= nums[i];
            end *= nums[sz - i - 1];
            max_prod = max(max_prod, max(start, end));
            if(start == 0) {
                start = 1;
            }
            if(end == 0) {
                end = 1;
            }
        }
        return max_prod;
    }
};
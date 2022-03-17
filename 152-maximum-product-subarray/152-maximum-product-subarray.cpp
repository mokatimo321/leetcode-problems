class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 1, right = 1, max_prod = INT_MIN;
        int sz = nums.size();
        for(int i = 0;i<nums.size();i++) {
            left *= nums[i];
            max_prod = max(max_prod, left);
            right *= nums[sz - i - 1];
            max_prod = max(max_prod, right);
            if(left == 0) {
                left = 1;
            }
            if(right == 0) {
                right = 1;
            }
        }
        return max_prod;
    }
};
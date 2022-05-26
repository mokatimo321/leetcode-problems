class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> mo(2*n, 0);
        int x = 0, y = n, i = 0;
        while(i < 2*n) {
            mo[i] = nums[x];
            x++, i++;
            mo[i] = nums[y];
            y++, i++;
        }
        return mo;
    }
};
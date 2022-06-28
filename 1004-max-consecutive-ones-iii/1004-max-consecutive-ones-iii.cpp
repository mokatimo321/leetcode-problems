class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        //using 2 pointer approach
        int start = 0, end = 0;
        int max_len = 0;
        
        //start traversing the array
        while(end < nums.size()) {
            if(nums[end] == 1) {
                end++;
            }
            else if(nums[end] == 0 && k > 0) {
                end++;
                k--;
            }
            else if(nums[end] == 0 && k == 0) {
                while(nums[start] != 0) {
                    start++;
                }
                start++;
                k++;
            }
            max_len = max(max_len, end - start);
            //cout<<max_len<<endl;
        }
        
        return max_len;
        
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        vector<string> res;
        long long first = nums[0], last = 0;
        int fl = 0;
        for(int i = 1;i<nums.size();i++) {
            if(nums[i-1] + 1 != nums[i]) {
                if(fl) {
                    res.push_back(to_string(first) + "->" + to_string(last));
                    first = nums[i];
                    last = 0;
                    fl = 0;
                }
                else {
                    res.push_back(to_string(first));
                    first = nums[i];
                }
            }
            else {
                last = nums[i];
                fl = 1;
            }
        }
        if(fl) {
            res.push_back(to_string(first) + "->" + to_string(last));
        }
        else {
            res.push_back(to_string(first));
        }
        return res;
    }
};
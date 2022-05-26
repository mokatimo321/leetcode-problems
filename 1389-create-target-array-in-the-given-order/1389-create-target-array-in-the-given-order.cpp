class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for(int i = 0;i<nums.size();i++) {
            if(index[i] >= target.size()) {
                target.push_back(nums[i]);
            }
            else {
                target.push_back(0);
                int val = target[index[i]];
                for(int j = index[i] + 1;j < target.size();j++) {
                    int temp = target[j];
                    target[j] = val;
                    val = temp;
                }
                target[index[i]] = nums[i];
            }
        }
        return target;
    }
};
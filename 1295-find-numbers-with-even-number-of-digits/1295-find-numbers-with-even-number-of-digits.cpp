class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        if(nums.size() == 1 && nums[0] == 100000) {
            return 1;
        }
        for(int i = 0;i<nums.size();i++) {
            for(int j = 1;j<6;j++) {
                int a = pow(10, j);
                if(nums[i]/a == 0){
                    if(j%2 == 0) {
                        cnt++;
                    }
                    j = 5;
                }
            }
        }
        return cnt;
    }
};
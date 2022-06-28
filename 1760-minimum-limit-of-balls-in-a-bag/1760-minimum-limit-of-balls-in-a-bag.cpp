class Solution {
public:
    
    bool check(vector<int> nums, int max_op, int mid) {
        
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] > mid) {
                max_op -= nums[i]/mid;
                if(nums[i]%mid == 0) {
                    max_op++;
                }
            }
            if(max_op < 0) {
                return false;
            }
        }
        
        return true;
    }
    
    int minimumSize(vector<int>& nums, int max_op) {
        
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        
        while(high >= low) {
            
            int mid = low + (high - low)/2;
            if(check(nums, max_op, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            
            //cout<<low<<"---"<<mid<<"---"<<high<<endl;
            
        }
        
        return ans;
        
    }
};
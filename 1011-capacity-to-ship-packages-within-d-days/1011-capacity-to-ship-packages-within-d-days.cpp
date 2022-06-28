class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 0, high = 0, req_days = 0;
        int max_allowed = 0, ans = INT_MAX;
        for(int i = 0;i<weights.size();i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }
        
        while(high >= low) {
            
            max_allowed = low + (high - low)/2;
            int temp = 0;
            req_days = 0;
            for(int i = 0;i<weights.size();i++) {
                temp += weights[i];
                if(temp >= max_allowed) {
                    req_days++;
                    if(temp > max_allowed) {
                        temp = weights[i];
                    }
                    else {
                        temp = 0;
                    }
                }
            }
            if(temp > 0) {
                req_days++;
            }
            if(req_days <= days) {
                ans = min(ans, max_allowed);
                high = max_allowed - 1; 
            }
            else if(req_days > days) {
                low = max_allowed + 1;
            }
            
        }
        
        return ans;
        
    }
};
class Solution {
public:
    
    int cache[31][1001];
    
    int num_ways(int n, int k, int target) {
        
        //base case
        if(n == 0 && target == 0) {
            return 1;
        }
        
        if(n < 0 || target < 0) {
            return 0;
        }
        
        if(cache[n][target] != -1) {
            return cache[n][target];
        }
        
        int total_ways = 0;
        
        for(int i = 1;i<=k && i <= target;i++) {
            int cnt = num_ways(n-1, k, target-i);
            total_ways = (total_ways + cnt)%1000000007;
        }
        
        cache[n][target] = total_ways;
        return total_ways;
        
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        memset(cache, -1, sizeof(cache));
        return num_ways(n, k, target);
    }
};
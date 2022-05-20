class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        
        for(int i = 0;i<edges.size();i++) {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        
        int ans = 0;
        for(auto x : mp) {
            if(x.second > mx) {
                mx = x.second;
                ans = x.first;
            } 
        }
            
        return ans;
            
    }
};
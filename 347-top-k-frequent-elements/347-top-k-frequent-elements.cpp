class Solution {
public:
    
    static int cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    
    void mo(vector<int> n, unordered_map<int, int> &mp) {
        for(int i = 0;i<n.size();i++) {
            mp[n[i]]++;
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mo(nums, mp);
        vector<int> momo;
        int c = 0;
        
        vector<pair<int, int>> m(mp.begin(), mp.end());
        
        sort(m.begin(), m.end(), cmp);
        //reverse(m.begin(), m.end());
        
        for(int i = 0;i<m.size();i++) {
            momo.push_back(m[i].first);
            c++;
            if(c == k) {
                break;
            }
        }
        
        return momo;
        
    }
};
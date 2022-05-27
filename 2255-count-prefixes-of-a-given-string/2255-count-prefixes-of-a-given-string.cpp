class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        
        unordered_map<string, int> mp;
        string res = "";
        
        for(int i = 0;i<s.length();i++) {
            res += s[i];
            mp[res]++;
        }
        
        int cnt = 0;
        
        for(int i = 0;i<words.size();i++) {
            if(mp[words[i]]) {
                cnt++;
            }
        }
        
        return cnt;
        
    }
};
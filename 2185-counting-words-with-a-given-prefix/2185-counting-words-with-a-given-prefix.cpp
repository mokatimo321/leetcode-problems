class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt = 0, pref_length = pref.length();
        
        for(int i = 0;i<words.size();i++) {
            if(words[i].substr(0, pref_length) == pref) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
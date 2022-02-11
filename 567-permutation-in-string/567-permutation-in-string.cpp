class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26, 0); // for s1
        vector<int> m2(26, 0); // for s2
        if(s1.length() > s2.length()) {
            return false;
        }
        for(int i = 0;i<s1.length();i++) {
            m1[int(s1[i]) - 97] += 1;
        }
        int sz = s1.length();
        int i = 0;
        for(i;i<sz;i++) {
            m2[int(s2[i]) - 97] += 1;
        }
        if(m1 == m2) {
            return true;
        }
        for(i;i<s2.length();i++) {
            m2[int(s2[i-sz]) - 97] -= 1;
            m2[int(s2[i]) - 97] += 1;
            if(m1 == m2) {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    string convert(string s, int nr) {
        if(s.length() == 1 || nr == 1) {
            return s;
        }
        vector<string> mo(nr, "");
        int j = 0;
        int fl1 = 1;
        int fl2 = 0;
        for(int i = 0;i<s.length();i++) {
            if(fl1 == 1) {
                mo[j] += s[i];
                if(j == nr - 1) {
                    fl1 = 0;
                    fl2 = 1;
                    j--;
                }
                else {
                    j++;
                }
            }
            else if(fl2 == 1) {
                mo[j] += s[i];
                if(j == 0) {
                    fl2 = 0;
                    fl1 = 1;
                    j++;
                }
                else {
                    j--;
                }
            }
        }
        for(int i = 1;i<mo.size();i++) {
            mo[0] += mo[i];
        }
        return mo[0];
    }
};
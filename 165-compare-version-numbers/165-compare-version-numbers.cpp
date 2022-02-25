class Solution {
public:
    
    vector<int> convert(string v) {
        vector<int> res;
        int temp = 0;
        for(int i = 0;i<v.length();i++) {
           if(v[i] == '.') {
               // if(temp != 0) {
               //     res.push_back(temp);
               // }
               res.push_back(temp);
               temp = 0;
           }
           else {
               temp = temp*10 + (int(v[i]) - 48);
           } 
        }
        // if(temp != 0) {
        //    res.push_back(temp);
        // }
        res.push_back(temp);
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1 = convert(version1);
        vector<int> v2 = convert(version2);
        if(v1.size() > v2.size()) {
            while(v1.size() != v2.size()) {
                v2.push_back(0);
            }
        }
        else if(v2.size() > v1.size()) {
            while(v1.size() != v2.size()) {
                v1.push_back(0);
            }
        }
        int i = 0;
        while(i < v1.size()) {
            if(v1[i] > v2[i]) {
                return 1;
            }
            else if(v2[i] > v1[i]) {
                return -1;
            }
            i++;
        }
        return 0;
    }
};
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> mo;
        for(int i = 0;i<arr.size();i++) {
            mo.push_back(arr[i]);
            if(mo.size() == arr.size()) {
                arr = mo;
                break;
            }
            if(arr[i] == 0) {
                mo.push_back(arr[i]);
            }
            if(mo.size() == arr.size()) {
                arr = mo;
                break;
            }
        }
        arr = mo;
    }
};
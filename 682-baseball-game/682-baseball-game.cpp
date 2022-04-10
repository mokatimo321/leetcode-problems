class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> mo;
        int index = 0;
        for(int i = 0;i<ops.size();i++) {
            if(ops[i] == "+") {
                mo.push_back(mo[index-1] + mo[index - 2]);
                index++;
            }
            else if(ops[i]== "C") {
                mo.pop_back();
                index--;
            }
            else if(ops[i] == "D") {
                mo.push_back(mo[index - 1]*2);
                index++;
            }
            else {
                mo.push_back(stoi(ops[i]));
                index++;
            }
        }
        return accumulate(mo.begin(), mo.end(), 0);
    }
};
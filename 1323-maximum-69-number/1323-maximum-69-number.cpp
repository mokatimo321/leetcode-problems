class Solution {
public:
    int maximum69Number (int num) {
        vector<int> dig;
        while(num) {
            dig.push_back(num%10);
            cout<<num%10<<endl;
            num /= 10;
        }
        reverse(dig.begin(), dig.end());
        for(int i = 0;i < dig.size();i++) {
            if(dig[i] == 6) {
                dig[i] = 9;
                break;
            }
        }
        int target = 0;
        for(int i = 0;i<dig.size();i++) {
            target = target*10 + dig[i];
        }
        return target;
    }
};
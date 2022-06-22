class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        priority_queue<int> q;
        
        int temp = arr[0], cnt = 0;
        
        for(int i = 0;i<arr.size();i++) {
            if(arr[i] == temp) {
                cnt++;
            }
            else {
                q.push(cnt);
                cnt = 1;
                temp = arr[i];
            }
        }
        
        if(cnt) {
            q.push(cnt);
        }
        
        cnt = 0, temp = 0;
        
        while(q.size()) {
            temp += q.top();
            cnt++;
            q.pop();
            if(temp >= arr.size()/2) {
                return cnt;
            }
        }
        
        return cnt;
        
    }
};
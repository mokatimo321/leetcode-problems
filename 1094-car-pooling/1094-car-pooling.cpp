class Solution {
public:
    bool carPooling(vector<vector<int>>& tr, int cp) {
        
        typedef pair<int, int> pi;
        
        //interchanging the first and second index every vector to be able to sort based on the pickup time
        for(int i = 0;i<tr.size();i++) {
            int temp = tr[i][1];
            tr[i][1] = tr[i][0];
            tr[i][0] = temp;
        }
        
        //sorted based on the basis of pick-up location
        sort(tr.begin(), tr.end());
        int end = -1, current_cap = 0;
        
        //we also need to maintain a priority queue to remove the passenger whose journey is over while onboarding any new passenger
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        //traverse the array
        for(int i = 0;i<tr.size();i++) {
            //intersecting location
            if(end > tr[i][0]) {
                //mixed state
                while(pq.size() > 0 && tr[i][0] >= pq.top().first) {
                    current_cap -= pq.top().second;
                    pq.pop();
                }
                if(current_cap + tr[i][1] > cp) {
                    return false;
                }
                current_cap += tr[i][1];
                end = max(end, tr[i][2]);
                pq.push({tr[i][2], tr[i][1]});
            }
            else {
                //clean state
                current_cap = tr[i][1];
                if(current_cap > cp) {
                    return false;
                }
                end = tr[i][2];
                //empty the current priority queue
                while(pq.size() > 0) {
                    pq.pop();
                }
                pq.push({tr[i][2], tr[i][1]});
            }
        }
        
        return true;
        
    }
};
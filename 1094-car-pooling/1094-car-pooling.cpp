class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        //approach
        //sort the trips time based on the time of pickup
        //check whether thera are alreay any passengers or not
        //Also maintain a priority queue to deboard some passengers when there trip is over while onboarding new passengers
        //check whether there are any passengers still inside the car, if then check with the capacity
        //if no passengers || start time > max(all the prior end times) which indicates that it is a fresh pickup thus we empty our existing priority queue
        
        //to sort on the basis of second element || first index we can either swap the values ot use lambda function to achieve it
        //we will be swapping
        
        for(int i = 0;i<trips.size();i++) {
            int temp = trips[i][0];
            trips[i][0] = trips[i][1];
            trips[i][1] = temp;
        }
        
        //sort the array based on the pickup time
        sort(trips.begin(), trips.end());
        
        //maintain a priority queue (min Heap)
        typedef pair<int, int> pr;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        
        //max end time
        int end = -1;
        
        //travers the trips vector
        for(int i = 0;i<trips.size();i++) {
            //clean state
            if(trips[i][0] >= end) {
                while(pq.size() > 0) {
                    capacity += pq.top().second;
                    pq.pop();
                }
                if(trips[i][1] <= capacity) {
                    capacity -= trips[i][1];
                    pq.push({trips[i][2], trips[i][1]});
                    end = max(end, trips[i][2]);
                }
                else {
                    return false;
                }
                
            }
            //mixed state --> some passengers are already there
            else {
                while(pq.size() > 0 && pq.top().first <= trips[i][0]) {
                    capacity += pq.top().second;
                    pq.pop();
                }
                if(trips[i][1] <= capacity) {
                    capacity -= trips[i][1];
                    end = max(end, trips[i][2]);
                    pq.push({trips[i][2], trips[i][1]});
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
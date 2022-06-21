class Solution {
public:
    int furthestBuilding(vector<int>& ht, int b, int l) {
        
        priority_queue<int> q;
        int i = 0, dist = 0;
        
        for(i;i<ht.size() - 1;i++) {
            dist = ht[i+1] - ht[i];
            if(dist <= 0) {
                continue;
            }
            else {
                if(b >= dist) {
                    q.push(dist);
                    b -= dist;
                }
                else if(q.size() > 0 && q.top() >= dist && l > 0) {
                    b = (b + q.top()) - dist;
                    q.pop();
                    q.push(dist);
                    l--;
                }
                else {
                    if(l > 0) {
                        l--;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        
        return i;
        
    }
};
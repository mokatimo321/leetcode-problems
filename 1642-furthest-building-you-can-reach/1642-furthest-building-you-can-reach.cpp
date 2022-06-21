class Solution {
public:
    
    bool check(vector<int> ht, int b, int l, int index) {
        
        //store the height differences which requires bricks or ladders
        vector<int> diff;
        for(int i = 0;i<index;i++) {
            if(ht[i+1] > ht[i]) {
                diff.push_back(ht[i+1] - ht[i]);
            }
        }
        
        //sort the differences verctor in decreasing order
        sort(diff.begin(), diff.end(), greater<int>());
        
        //to check whther all the differences cxan be covered using bricks & ladders or not
        for(int i = 0;i<diff.size();i++) {
            if(l) {
                l--;
            }
            else {
                if(b >= diff[i]) {
                    b-= diff[i];
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    
    int furthestBuilding(vector<int>& ht, int b, int l) {
        
        int low = 0, high = ht.size()-1;
        int mid = 0;
        
        while(low < high) {
            
            mid = (low + high + 1)/2;
            //cout<<mid<<endl;
            
            if(check(ht, b, l, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
            
        }
        
        return low;
        
        
    }
};
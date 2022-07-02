class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        hc.push_back(h);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int l = hc[0] - 0, b = vc[0] - 0;
        const unsigned int M = 1000000007;
        
        for(int i = 0;i<hc.size() - 1;i++) {
            l = max(l, hc[i+1] - hc[i]);
        }
        
        for(int i = 0;i<vc.size() - 1;i++) {
            b = max(b, vc[i+1] - vc[i]);
        }
        
        
        return (1LL*l*b)%M;
        
    }
};
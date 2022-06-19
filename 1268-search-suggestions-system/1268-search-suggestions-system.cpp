class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //sort the products array
        sort(products.begin(), products.end());
        
        
        unordered_map<string, vector<string>> mp;
        string s = "";
        
        //store the substring formed into the hashmap
        for(int i = 0;i<products.size();i++) {
            s = "";
            for(int j = 0;j<products[i].length();j++) {
                s += products[i][j];
                mp[s].push_back(products[i]);
            }
        }
        
        //to store the final answer
        vector<vector<string>> res;
        s = "";
        
        for(int i = 0;i<searchWord.length();i++) {
            s += searchWord[i];
            if(mp[s].size() > 3) {
                res.push_back({mp[s][0], mp[s][1], mp[s][2]});
            }
            else {
                res.push_back(mp[s]);
            }
        }
        
        return res;
        
    }
};
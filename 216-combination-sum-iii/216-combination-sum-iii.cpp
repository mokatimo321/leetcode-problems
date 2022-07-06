class Solution {
public:
    
    void combine(int curr_sum, int num_elements, vector<int> fill, vector<vector<int>> &result ,int index) {
        
        //base case
        if(curr_sum == 0 && num_elements == 0) {
            result.push_back(fill);
            return;
        }
        
        
        for(int i = index;i<=9;i++) {
            if(curr_sum < 0) {
                break;
            }
            if(num_elements < 0) {
                break;
            }
            fill.push_back(i);
            combine(curr_sum - i, num_elements - 1, fill, result, i + 1);
            fill.pop_back();
        }

    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        combine(n, k, {}, result, 1);
        return result;
    }
};
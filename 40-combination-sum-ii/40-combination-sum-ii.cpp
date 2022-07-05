class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target,int index,  vector<int> curr){
        
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        
        for(int k=index; k<candidates.size() ;k++){
            
            // becuase of this step we will not include duplicates 
            if(k>index && candidates[k]==candidates[k-1])
                continue;
            
            // if the current element is greater , then all the elements after it will be useless , as we had sorted the  array  candidates.
            if(candidates[k]>target)
                break;
            
            // now if the first two conditions are not satisfied then we can include this in our curr array  and then see recursively that can we get  to the sum target by including other values in the candidates array
            curr.push_back(candidates[k]);
            
            solve(candidates,target-candidates[k],k+1,curr);
            
            // backtrack
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        int index=0;
        solve(candidates,target,index,curr);
        
        return ans;
    }
};
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void dfs(int id, unordered_map<int, Employee*> mp, int &sum) {
        sum += mp[id]->importance;
        for(int i = 0;i<mp[id]->subordinates.size();i++) {
            dfs(mp[id]->subordinates[i], mp, sum);
        }
    }
    
    
    
    int getImportance(vector<Employee*> emp, int id) {
        
        //standard graph question
        //keep a map to have a track of the index using id
        
        //id -> mapped with the index in the employee vector
        unordered_map<int, Employee*> mp;
        for(auto x : emp) {
            mp[x->id] = x;
        }
        
        //to keep a track of the answer
        int sum = 0;
        
        //now we will do the dfs to get the importance of the given employee
        dfs(id, mp, sum);
        return sum;
        
    }
};
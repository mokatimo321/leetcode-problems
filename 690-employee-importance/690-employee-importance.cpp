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
    
    int dfs(int id, unordered_map<int, Employee*> mp) {
        int sum = 0;
        for(int i = 0;i<mp[id]->subordinates.size();i++) {
            sum += dfs(mp[id]->subordinates[i], mp);
        }
        return sum + mp[id]->importance;
    }
    
    
    
    int getImportance(vector<Employee*> emp, int id) {
        
        //standard graph question
        //keep a map to have a track of the index using id
        
        //id -> mapped with the index in the employee vector
        unordered_map<int, Employee*> mp;
        for(auto x : emp) {
            mp[x->id] = x;
        }
        
        //now we will do the dfs to get the importance of the given employee
        return dfs(id, mp);
        
    }
};
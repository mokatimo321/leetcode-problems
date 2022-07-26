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
    
    //approach
    //we will keep every instance of employee class in a map, mapped with its id
    int dfs(unordered_map<int, Employee*> mp, int id) {
        
        int current_sum = mp[id]->importance;
        for(int i = 0;i<mp[id]->subordinates.size();i++) {
            current_sum += dfs(mp, mp[id]->subordinates[i]);
        }
        
        //return the result
        return current_sum;
        
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(int i = 0;i<employees.size();i++) {
            mp[employees[i]->id] = employees[i];
        }
        return dfs(mp, id);
    }
};
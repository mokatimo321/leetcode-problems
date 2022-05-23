class Solution {
public:
    
    void solve(vector<vector<int>> rooms, vector<bool> &visited) {
        
        for(int i = 0;i<rooms[0].size();i++) {
            if(visited[rooms[0][i]] == false) {
                traverse(rooms, visited, rooms[0][i]);
            }
        }
    }
    
    void traverse(vector<vector<int>> rooms, vector<bool> &visited, int current) {
        
        visited[current] = true;
        for(int i = 0;i<rooms[current].size();i++) {
            if(visited[rooms[current][i]] == false) {
                traverse(rooms, visited, rooms[current][i]);
            }
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(), false);
        solve(rooms, visited);
        
        visited[0] = true;
        for(int i = 0;i<visited.size();i++) {
            if(visited[i] == 0) {
                return false;
            }
        }
        
        return true;
        
    }
};
class Solution {
public:
    
    void FindProv(vector<vector<int>> adj, vector<bool> &visited, int &cnt) {
        for(int i = 0;i<adj.size();i++) {
            if(visited[i] == false) {
                int current = i;
                cnt++;
                traverse(adj, visited, current);
            }
        }
    }
    
    void traverse(vector<vector<int>> adj, vector<bool> &visited, int current) {
        visited[current] = true;
        for(int i = 0;i<adj[current].size();i++) {
            if(adj[current][i] == 1 && visited[i] == false) {
                traverse(adj, visited, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int cnt = 0;
        FindProv(isConnected, visited, cnt);
        return cnt;
    }
};
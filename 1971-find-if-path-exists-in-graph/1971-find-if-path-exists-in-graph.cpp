class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        
        vector<vector<int>> graph(n);
        
        for(int i = 0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        vector<int> visited(n, 0);
        
        q.push(src);
        
        while(!q.empty()) {
            
            int current = q.front();
            q.pop();
            visited[current] = 1;
            
            if(current == dst) {
                return true;
            }
            
            for(int i = 0;i<graph[current].size();i++) {
                if(visited[graph[current][i]] == 0) {
                    q.push(graph[current][i]);
                    visited[graph[current][i]] = 1;
                }
            }
            
        }
        
        return false;
        
    }
};
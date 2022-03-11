class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        
        vector<vector<int>> graph(n);
        
        for(int i = 0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n, 0);
        
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        
        while(!q.empty()) {
            
            int top = q.front();
            q.pop();
            
            if(top == dst) {
                return true;
            }
            
            for(int i = 0;i<graph[top].size();i++) {
                if(visited[graph[top][i]] == 0) {
                    q.push(graph[top][i]);
                    visited[graph[top][i]] = 1;
                }
            }
            
            
        }
        
        return false;
        
    }
};
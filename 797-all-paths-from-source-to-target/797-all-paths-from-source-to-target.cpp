class Solution {
public:
    
    void PrintPath(vector<vector<int>> graph, vector<int> PathSoFar, vector<vector<int>> &result, int src, int dst, vector<bool> visited) {
        
        //base case
        if(src == dst) {
            PathSoFar.push_back(src);
            result.push_back(PathSoFar);
            return;
        }
        
        visited[src] = true;
        PathSoFar.push_back(src);
        
        for(int i = 0;i<graph[src].size();i++) {
            if(visited[graph[src][i]] == false) {
                PrintPath(graph, PathSoFar, result, graph[src][i], dst, visited);
            }
        }
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<int> PathSoFar;
        vector<bool> visited(graph.size(), false);
        
        int src = 0;
        int dst = graph.size() - 1;
        
        PrintPath(graph, PathSoFar, result, src, dst, visited);
        return result;
        
    }
};
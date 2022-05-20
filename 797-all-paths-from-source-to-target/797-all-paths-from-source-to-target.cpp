class Solution {
public:
    
    void PrintPath(vector<vector<int>> graph, vector<int> PathSoFar, vector<vector<int>> &result, int src, int dst) {
        
        //base case
        if(src == dst) {
            PathSoFar.push_back(src);
            result.push_back(PathSoFar);
            return;
        }
        
        PathSoFar.push_back(src);
        
        for(int i = 0;i<graph[src].size();i++) {
            PrintPath(graph, PathSoFar, result, graph[src][i], dst);
        }
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<int> PathSoFar;
        
        int src = 0;
        int dst = graph.size() - 1;
        
        PrintPath(graph, PathSoFar, result, src, dst);
        return result;
        
    }
};
class Solution {
public:
    void DFS(int cur,vector<vector<int>> &graph,vector<int> &path,vector<vector<int>> &paths){
        path.push_back(cur);
        if(cur == graph.size() - 1){
            paths.push_back(path);
            return;
        }
        for(auto i : graph[cur]){
          DFS(i,graph,path,paths);  
          path.pop_back();    
        }  
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> paths;
        DFS(0,graph,path,paths);
        return paths;
    }
};
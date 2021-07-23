class Solution {
public:
    void DFS(int cur,vector<vector<int>> &graph,vector<int> &path,vector<vector<int>> &paths,vector<bool> visited){
        if(cur == graph.size() - 1){
            path.push_back(cur);
            paths.push_back(path);
            return;
        }
        if(!visited[cur]){
          path.push_back(cur);  
          for(auto i : graph[cur]){
              DFS(i,graph,path,paths,visited);  
              path.pop_back();
              visited[cur] = false;
          }  
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<bool> visited(n,false);
        vector<vector<int>> paths;
        DFS(0,graph,path,paths,visited);
        return paths;
    }
};
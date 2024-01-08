class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
        visited[node] = true;
        for(int nei : graph[node]){
            if(!visited[nei]){
                dfs(graph, visited, nei);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto edge : edges){
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int count = 0;
        for(int node = 0; node < n; node++){
            if(!visited[node]){
                count++;
                dfs(graph, visited, node);
            }
        }
        return count;
    }
};
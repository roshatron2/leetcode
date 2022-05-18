class Solution {
public:
    vector<vector<int>> graph,res;
    vector<int> firstTime,minTime;
    vector<bool> visited;
    int time = 1;
    void dfs(int node,int parent){
        firstTime[node] = minTime[node] = time++;
        visited[node] = true;
        for(int nei : graph[node]){
            if(nei == parent)
                continue;
            if(!visited[nei]){
                dfs(nei,node);
            }    
            minTime[node] = min(minTime[node],minTime[nei]);
            
            if(firstTime[node] < minTime[nei]){
                res.push_back({node,nei});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       graph.resize(n);
       firstTime.resize(n);
       minTime.resize(n);
       visited.resize(n);
       for(auto connection : connections){
           int u = connection[0],v = connection[1];
           graph[u].push_back(v);
           graph[v].push_back(u);
       }
       dfs(0,0);
       return res; 
    }
};
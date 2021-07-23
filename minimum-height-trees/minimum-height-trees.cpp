class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;    
        if(edges.size() == 0){
            return {0};
        }
        vector<int> degree(n,0);
        vector<vector<int>> graph(n,vector<int>());
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)
                q.push(i);
        }
        
        while(n > 2){
            int num_of_leaves = q.size();
            n -= num_of_leaves;
            for(int i = 0; i < num_of_leaves; i++){
                int cur = q.front();
                q.pop();
                for(auto j : graph[cur]){
                    degree[j]--;
                    if(degree[j] == 1){
                        q.push(j);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
    
};
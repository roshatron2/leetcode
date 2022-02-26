class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> ordering,indegree(n,0);
        for(auto pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            ordering.push_back(cur);
            q.pop();
            for(int node : graph[cur]){
                indegree[node]--;
                if(indegree[node] == 0)
                    q.push(node);
            }
        }
        if(ordering.size() == n)
            return ordering;
        return {};
    }
};
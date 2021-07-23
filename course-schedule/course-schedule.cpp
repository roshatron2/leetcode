class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> degree(n,0);
        vector<vector<int>> adj(n,vector<int>());
        for(auto p : pre){
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            cout<<cur<<endl;
            q.pop();
            n--;
            for(auto i : adj[cur]){
                degree[i]--;
                if(degree[i] == 0)
                    q.push(i);
            }
        }
        return n == 0;
    }
};
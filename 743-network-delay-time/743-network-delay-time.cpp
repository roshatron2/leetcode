class Solution { 
    public: vector<pair<int,int>> adj[101]; 
    void bfs(vector<int> &signal,int k){ 
        queue<int> q; 
        q.push(k); 
        signal[k] = 0;
        
        while(!q.empty()){ 
            int cur = q.front(); 
            q.pop();
            for(auto node : adj[cur]){  
               int time = node.first;
               int nei = node.second;
                
               int arrivalTime = time + signal[cur];
               if(arrivalTime < signal[nei]){
                   signal[nei] = arrivalTime;
                   q.push(nei);
               }
            } 
        } 
    }  
    int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
        for(vector<int> time : times){ 
            int source = time[0]; 
            int dest = time[1]; 
            int travelTime = time[2]; 
            adj[source].push_back({travelTime,dest}); 
        } 
        vector<int> signal(n + 1,INT_MAX); 
        bfs(signal,k);
        int answer = INT_MIN; 
        for(int node = 1; node <= n; node++){ 
            answer = max(answer,signal[node]); 
        } 
        return answer == INT_MAX ? -1 : answer; 
    } 
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,int> map;
        queue<int> q; 
        for(int i = 0; i < n; i++){
            if(map.find(i) == map.end()){
                q.push(i);
                map[i] = 0;
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(int nei : graph[cur]){
                        if(map.find(nei) == map.end()){
                            map[nei] = map[cur] ^ 1;
                            q.push(nei);
                        } else if(map[nei] == map[cur]){
                            return false;
                        }
                    }
                }
            } 
        }
        return true;
    }
};
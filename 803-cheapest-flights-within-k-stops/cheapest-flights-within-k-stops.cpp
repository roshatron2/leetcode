class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;    
        unordered_map<int,vector<pair<int,int>>> graph(n);
        for( auto e : flights){
            graph[e[0]].push_back({e[1], e[2]});
        }
        vector<int> stops(n, INT_MAX);
        min_heap.push({0, src, 0});
        while(!min_heap.empty()){
            auto top = min_heap.top();
            min_heap.pop();

            int distance = top[0];
            int node = top[1];
            int steps = top[2];

            if(stops[node] < steps or steps  > k + 1){
                continue;
            }
            stops[node] = steps;
            if(node == dst){
                return distance;
            }
            for(auto [nei, cost] : graph[node]){
                min_heap.push({distance + cost, nei, steps + 1});
            }
        }
        return -1;
    }
};
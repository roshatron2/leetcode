class Solution {
private:
    int manhattan(vector<int> &p1, vector<int>& p2){
        int x0 = p1[0], x1 = p2[0];
        int y0 = p1[1], y1 = p2[1]; 
        return abs(x1 - x0) + abs(y1 - y0);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> costs(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                costs[i][j] = manhattan(points[i], points[j]);
            }
        }
        int cost = 0;
        set<int> visited;
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> min_heap(cmp);
        min_heap.push({0,0});
        while(visited.size() != n){
            pair<int,int> cur = min_heap.top();
            min_heap.pop();
            int dist = cur.first;
            int node = cur.second;
            if(visited.find(node) != visited.end()){
                continue;
            }
            visited.insert(node);
            cost += dist;
            for(int nei = 0; nei < n; nei++){
                int nei_cost = costs[node][nei];
                if(visited.find(nei) == visited.end()){
                    min_heap.push({nei_cost, nei});
                }
            }
        }
        return cost;
    }
};
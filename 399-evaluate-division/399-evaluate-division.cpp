class Solution {
   public:
    double bfs(string start, string end, unordered_map<string,vector<string>> &graph, unordered_map<string,double> &map) {
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        unordered_map<string, bool> visited;

        while (!q.empty()) {
            pair<string, double> cur = q.front();
            string node = cur.first;
            double val = cur.second;
            q.pop();
            if (node == end) {
                return val;
            }
            visited[node] = true;
            for (string nei : graph[node]) {
                if (visited.find(nei) == visited.end()) {
                    q.push({nei, val * map[node + "->" + nei]});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double> map;
        unordered_map<string, vector<string>> graph;
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            map[u + "->" + v] = values[i];
            map[v + "->" + u] = 1 / values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (vector<string> query : queries) {
            string start = query[0];
            string end = query[1];
            if(graph.find(start) == graph.end() or graph.find(end) == graph.end()){
                res.push_back(-1);
                continue;
            }
                
            double ans = bfs(start, end, graph, map);
            res.push_back(ans);
        }
        return res;
    }
};
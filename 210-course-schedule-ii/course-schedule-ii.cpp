class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, unordered_set<int>& visited, unordered_set<int>& cycle,  vector<int>& ordering){
        if(cycle.find(node) != cycle.end()){
            return false;
        }
        if(visited.find(node) != visited.end()){
            return true;
        }
        cycle.insert(node);
        for(int nei : graph[node]){
            if(!dfs(graph, nei, visited, cycle, ordering)){
                return false;
            }
        }
        cycle.erase(node);
        visited.insert(node);
        ordering.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for(vector<int> pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> visited, cycle;
        vector<int> ordering;
        for(int course = 0; course < numCourses; course++){
            if(!dfs(graph, course, visited, cycle, ordering)){
                return {};
            }
        }
        return ordering;
    }
};
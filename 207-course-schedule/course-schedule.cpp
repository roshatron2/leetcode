class Solution {
public:
    bool dfs(vector<vector<int>>& graph, unordered_set<int> visited, int course){
        if(visited.find(course) != visited.end()){
            return false;
        }
        if(graph[course].empty()){
            return true;
        }
        visited.insert(course);
        for(int pre : graph[course]){
            if(!dfs(graph, visited, pre)){
                return false;
            };
        }
        visited.erase(course);
        graph[course] = {};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for(vector<int> pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> visited;
        for(int course = 0; course < graph.size(); course++){
            if(!dfs(graph, visited, course)){
                return false;
            };
        }
        return true;
    }
};
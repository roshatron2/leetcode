class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for(vector<int> pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        for(vector<int> edges : graph){
            for(int v : edges){
                indegrees[v]++;
            }
        }
        for(int i = 0; i < numCourses; i++){
            int j = 0; 
            for(; j < numCourses; j++){
                if(!indegrees[j]){
                    break;
                }
            } 
            if(j == numCourses){
                return false;
            }
            indegrees[j]--;
            for(int nei : graph[j]){
                indegrees[nei]--;
            }
        }
        return true;
    }
};
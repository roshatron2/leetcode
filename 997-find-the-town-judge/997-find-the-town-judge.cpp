class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1,0),outdegree(n + 1,0);
        
        for(auto pair : trust){
            outdegree[pair[0]]++;
            indegree[pair[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(outdegree[i] == 0 and indegree[i] == n - 1)
                return i;
        }
        return -1;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1,0);
        vector<int> outdegree(n + 1,0);
        if(trust.size() == 0 and n == 1){
            return n;
        }
        for(int i = 0; i < trust.size(); i++){
            outdegree[trust[i][0]] += 1;
            indegree[trust[i][1]] += 1;
        }
        for(int i = 0; i <= n ;i++){
            if(indegree[i] == n - 1 and outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
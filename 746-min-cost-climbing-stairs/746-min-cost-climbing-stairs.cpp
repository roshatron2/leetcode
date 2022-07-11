class Solution {
public:
    unordered_map<int,int> memo;
    int dfs(vector<int> &cost,int i){
       if(memo[i]){
           return memo[i];
       }
       if(i >= cost.size()){
           return 0;
       } 
       return memo[i] = cost[i] + min(dfs(cost,i + 1),dfs(cost,i + 2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
       return min(dfs(cost,0),dfs(cost,1)); 
    }
};
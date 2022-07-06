class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
       int n = costs.size();
       vector<vector<int>> dp(n,vector<int>(3,0)); 
       dp[0] = costs[0];
       for(int i = 1; i < n; i++){
           for(int j = 0; j < 3; j++){
               if(j == 0){
                   dp[i][j] = costs[i][j] + min(dp[i - 1][1],dp[i - 1][2]);
               } else if(j == 1){
                   dp[i][j] = costs[i][j] + min(dp[i - 1][0],dp[i - 1][2]);
               } else {
                   dp[i][j] = costs[i][j] + min(dp[i - 1][0],dp[i - 1][1]);
               }
           }
       }
       return *min_element(dp[n - 1].begin(),dp[n - 1].end());
    }
};
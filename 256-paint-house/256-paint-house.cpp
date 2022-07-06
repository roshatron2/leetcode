class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
       int n = costs.size();
       vector<vector<int>> dp(n,vector<int>(3,0)); 
       dp[0] = costs[0];
       vector<int> prev = costs[0]; 
       for(int i = 1; i < n; i++){
           vector<int> cur(3,0);
           for(int j = 0; j < 3; j++){
               if(j == 0){
                   cur[j] = costs[i][j] + min(prev[1],prev[2]);
               } else if(j == 1){
                   cur[j] = costs[i][j] + min(prev[0],prev[2]);
               } else {
                   cur[j] = costs[i][j] + min(prev[0],prev[1]);
               }
           }
           prev = cur;
       }
       return *min_element(prev.begin(),prev.end());
    }
};
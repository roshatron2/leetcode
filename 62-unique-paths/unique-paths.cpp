class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int m, int n){
        if(dp[m][n]){
            return dp[m][n];
        }
        if(m == 0 or n == 0){
            return 0;
        }
        if(m == 1 and n == 1){
            return 1;
        }
        return dp[m][n] = dfs(m - 1, n) + dfs(m, n - 1);
    }
    int uniquePaths(int m, int n) {
       dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
       return dfs(m,n); 
    }
};
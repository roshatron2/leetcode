class Solution {
public:
    int dfs(int m,int n,vector<vector<int>>& memo){
        if(memo[m][n])
            return memo[m][n];
        if(m == 0 or n == 0)
            return 0;
        if(m == 1 and n == 1)
            return 1;
        memo[m][n] = dfs(m-1,n,memo) + dfs(m,n-1,memo);
        return memo[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 and j == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
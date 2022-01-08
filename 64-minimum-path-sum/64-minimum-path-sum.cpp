class Solution {
public:
    int dfs(int i,int j,int sum,vector<vector<int>> grid,vector<vector<int>> dp){
        int cur = grid[i][j];
        if(i == grid.size() - 1 and j == grid[0].size() - 1)
            return sum + cur;
        if(i == grid.size() - 1){
            dp[i][j] = dfs(i,j+1,sum + cur,grid,dp);
            return dp[i][j];
        } else if(j == grid[0].size() - 1){
            dp[i][j] = dfs(i + 1,j,sum + cur,grid,dp);
            return dp[i][j];
        }
        dp[i][j] = min(dfs(i,j + 1,sum + cur,grid,dp),dfs(i + 1,j,sum + cur,grid,dp));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,grid[0][0]));
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
Recursion with Memoization
```
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
vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
return dfs(0,0,0,grid,dp);
}
};
```
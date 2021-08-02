class Solution {
public:
    int dp[101][101];
    int dfs(vector<vector<int>> &grid,int i,int j){
        int m = grid.size(),n = grid[0].size();
        if(dp[i][j])
            return dp[i][j];
        if(i == m - 1 and j == n - 1){
            return 1;
        }
        if(i == m || j == n || grid[i][j])
            return 0;
        dp[i][j] = dfs(grid,i + 1,j) + dfs(grid,i,j+1);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        if(grid[0][0] or grid[m-1][n-1])
            return 0;
        return dfs(grid,0,0);
    }
};
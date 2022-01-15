class Solution {
public:
    int dp[201][201] = {0};
    int dfs(vector<vector<int>> grid,int i,int j,int cost){
        if(dp[i][j]){
            return dp[i][j];
        }
        if(i == grid.size() or j == grid[0].size()){
            return INT_MAX;
        }
        if(i == grid.size() - 1 and j == grid[0].size() - 1)
            return grid[i][j];
        dp[i][j] = grid[i][j] + min(dfs(grid,i+1,j,cost),dfs(grid,i,j+1,cost));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for(int i = 0; i < grid[0].size(); i++){
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{-1, 1}, {0, 1}, {1, 1}};
    int m, n;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(dp[i][j]){
            return dp[i][j];
        }
        if(i == grid.size() - 1 and j == grid[0].size() - 1){
            return 0;
        }

        int max_moves = 0;
        for(vector<int> dir : dirs){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size() 
                and grid[x][y] > grid[i][j]){
                    max_moves = max(max_moves, 1 + dfs(grid, x, y));
            }
        }
        return dp[i][j] = max_moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->dp.assign(m, vector<int>(n, 0));
        int max_moves = 0;
        for(int i = 0; i < m; i++){
            max_moves = max(max_moves, dfs(grid, i, 0));
        }
        return max_moves; 
    }
};
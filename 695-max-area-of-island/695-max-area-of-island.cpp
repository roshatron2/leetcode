class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j){
        if(i < 0 or j < 0 or i == grid.size() or j == grid[0].size()){
            return 0;
        }
        if(grid[i][j] != 1)
            return 0;
        int area = 0;
        grid[i][j] = 0;
        area = dfs(grid,i,j + 1) + dfs(grid,i + 1,j) + dfs(grid,i - 1,j) + dfs(grid,i,j - 1);
        return area + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    maxArea = max(maxArea,dfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i == -1 or i == grid.size() or j == - 1 or j == grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        for(vector<int> dir : dirs){
            dfs(grid, i + dir[0], j + dir[1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int num_of_islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    num_of_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return num_of_islands;
    }
};
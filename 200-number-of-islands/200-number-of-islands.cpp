class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>> &grid,int i,int j){
       if(i < 0 or i == grid.size() or j < 0 or j == grid[0].size()){
           return;
       } 
       if(grid[i][j] == '0'){
           return;
       }
       grid[i][j] = '0';
       for(vector<int> dir : dirs){
           int nx = i + dir[0];
           int ny = j + dir[1];
           dfs(grid,nx,ny); 
       }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                   islands++;
                   dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};
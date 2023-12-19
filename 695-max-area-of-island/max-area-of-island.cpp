class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int area(vector<vector<int>>& grid, int i, int j){
        if(i == grid.size() or j == grid[0].size() or i == -1 or j == -1){
            return 0;
        }
        if(grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        int cur_area = 1;
        for(vector<int> dir : dirs){
            cur_area += area(grid, i + dir[0], j + dir[1]);
        }
        return cur_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int cur = area(grid, i, j);
                    max_area = max(max_area, cur);
                }
            }
        }    
        return max_area;
    }
};
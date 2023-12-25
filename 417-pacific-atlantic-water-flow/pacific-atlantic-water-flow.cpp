class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool in_bounds(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        int rows = heights.size();
        int cols = heights[0].size();
        return i < rows and j < cols and i >= 0 and j >= 0 and !visited[i][j]; 
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        for(vector<int> dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            if(in_bounds(heights, visited, x,y) and heights[x][y] >= heights[i][j]){
                dfs(heights, visited, x, y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific_visited(rows, vector<bool>(cols,false));
        vector<vector<bool>> atlantic_visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < heights.size(); i++){
            dfs(heights, atlantic_visited, i, cols - 1);
            dfs(heights, pacific_visited, i, 0);
        }
        for(int j = 0; j < heights[0].size(); j++){
            dfs(heights, pacific_visited, 0, j);
            dfs(heights, atlantic_visited, rows - 1, j);
        } 
        vector<vector<int>> res;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific_visited[i][j] and atlantic_visited[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
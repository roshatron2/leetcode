class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '*'){
                    q.push({i,j});
                }
            }
        }        
        int steps = 0; 
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i = 0; i < size; i++){
                auto [x,y] = q.front(); 
                q.pop();
                for(auto dir : dirs){
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if(nx < 0 or ny < 0 or nx == m or ny == n){
                        continue;
                    }
                    if(grid[nx][ny] == 'X' or grid[nx][ny] == '&'){
                        continue;
                    }
                    if(grid[nx][ny] == '#'){
                        return steps;
                    }
                    grid[nx][ny] = '&';
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};
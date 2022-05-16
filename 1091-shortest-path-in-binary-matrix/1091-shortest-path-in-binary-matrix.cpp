class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        int steps = 0,m = grid.size(),n = grid[0].size();
        if(grid[0][0] == 1 or grid[m - 1][n - 1] == 1)
            return -1;
        while(!q.empty()){
           int size = q.size();
           steps++;
           for(int i = 0; i < size; i++){
               pair<int,int> cur = q.front();
               q.pop();
               int x = cur.first;
               int y = cur.second;
               grid[x][y] = 1;
               if(x == n - 1 and y == m - 1){
                   return steps;
               }
               for(auto dir : dirs){
                   int nx = x + dir[0];
                   int ny = y + dir[1];
                   if(nx < 0 or ny < 0 or nx == m or ny == n){
                       continue;
                   }
                   if(grid[nx][ny] == 0){
                       q.push({nx,ny});
                       grid[nx][ny] = 1;
                   }
               }
           }
           
        }
        return -1;
    }
};
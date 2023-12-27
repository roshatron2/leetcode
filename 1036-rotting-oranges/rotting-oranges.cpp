class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        int rotten = 0, fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        if(!fresh)
            return time;
        while(!q.empty()){
            int size = q.size();
            if(!fresh)
                break;
            for(int i = 0; i < size; i++){
                pair<int,int> top = q.front();
                q.pop();
                for(vector<int> dir : dirs){
                    int x = top.first + dir[0], y = top.second + dir[1];
                    if(x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == 1){
                        fresh--;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            time++;
        }
        if(!fresh)
            return time;
        else
            return -1;
    }
};
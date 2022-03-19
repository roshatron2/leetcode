class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int time = -1,x,y;
        int freshOranges = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0;j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int,int> cur = q.front();
                q.pop();
                for(auto dir : dirs){
                    x = cur.first + dir[0];
                    y = cur.second + dir[1];
                    if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size() and grid[x][y] == 1){
                        grid[x][y] = 2;
                        freshOranges--;
                        q.push({x,y});
                    }
                }
            }
            time++;
        }
        if(freshOranges)
            return -1;
        return time == -1 ? 0 : time;
    }
};
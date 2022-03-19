class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int x,y;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(auto dir : dirs){
                x = cur.first + dir[0];
                y = cur.second + dir[1];    
                if(x >= 0 and y >= 0 and x < mat.size() and y < mat[0].size() and mat[x][y] == -1){
                    mat[x][y] = 1 + mat[cur.first][cur.second];
                    q.push({x,y});
                }
            }
        }
        return mat;
    }
};
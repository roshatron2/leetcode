class Cell{
public:
    int x,y,diff;
    Cell(int x,int y,int diff){
       this->x = x;
       this->y = y;
       this->diff = diff;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> diffMatrix(m,vector<int>(n,INT_MAX));
        diffMatrix[0][0] = 0;
        auto cmp = [](Cell a,Cell b){
            return a.diff > b.diff;
        };
        priority_queue<Cell,vector<Cell>,decltype(cmp)> q(cmp);
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        q.push(Cell(0,0,diffMatrix[0][0]));
        
        while(!q.empty()){
            Cell cur = q.top();
            q.pop();
            visited[cur.x][cur.y] = true;
            
            if(cur.x == m - 1 and cur.y == n - 1)
                return cur.diff;
            for(auto dir : dirs){
                int x = cur.x + dir[0];
                int y = cur.y + dir[1];
                
                if(x >= 0 and y >= 0 and x < m and y < n and !visited[x][y]){
                    int curDiff = abs(heights[x][y] - heights[cur.x][cur.y]);
                    int maxDiff = max(curDiff,diffMatrix[cur.x][cur.y]);
                    
                    if(diffMatrix[x][y] > maxDiff){
                        diffMatrix[x][y] = maxDiff;
                        q.push(Cell(x,y,maxDiff));
                    }
                }
            }
        }
        return diffMatrix[m - 1][n - 1];
    }
};
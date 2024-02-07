class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp);       
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        min_heap.push({grid[0][0], 0, 0});
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int res = INT_MAX;
        
        while(!min_heap.empty()){
            vector<int> cur = min_heap.top();
            min_heap.pop();
            int height = cur[0];
            int i = cur[1];
            int j = cur[2];
            visited[i][j] = true;
            if(i == n - 1 and j == n - 1){
                res = min(res, height);
            }
            for(vector<int> dir : dirs){
                int x = i + dir[0];
                int y = j + dir[1];
                if(x >= 0 and y >= 0 and x < n and y < n and !visited[x][y]){
                    min_heap.push({ max(grid[x][y], height), x, y });
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 or j < 0 or i == board.size() or j == board[0].size()){
            return;
        }
        if(board[i][j] == 'X' or visited[i][j]){
            return;
        }
        cout << i << j << endl;
        visited[i][j] = true;
        for(vector<int> dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            dfs(board, visited, x, y);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            dfs(board, visited, i, 0);
            dfs(board, visited, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            dfs(board, visited, 0, j);
            dfs(board, visited, m - 1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] and board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
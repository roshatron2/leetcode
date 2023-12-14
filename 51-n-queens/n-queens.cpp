class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<string>& board, int x, int y){
        for(int i = x - 1; i >= 0; i--){
            if(board[i][y] == 'Q'){
                return false;
            }
        }
        for(int i = y - 1; i >= 0; i--){
            if(board[x][i] == 'Q'){
                return false;
            }
        }
        vector<vector<int>> dirs = {{-1, -1}, {-1, 1}};
        for(vector<int> dir : dirs){
            int i = x, j = y;
            while(true){
                i += dir[0];
                j += dir[1];
                if(i < 0 or i == board.size() or j < 0 or j == board.size()){
                    break;
                }
                if(board[i][j] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(vector<string>& board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        for(int col = 0; col < board.size(); col++){
            board[row][col] = 'Q';
            if(isValid(board, row, col)){
                dfs(board, row + 1);
            }
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));     
        dfs(board, 0);
        return res;
    }
};
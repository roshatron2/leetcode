class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q' && i != row)
                return false;
        }

        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q' && i != col)
                return false;
        }

        int i = row + 1;
        int j = col + 1;
        while (i < n && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        i = row - 1;
        j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool backtrack(vector<string> &board,int row,int n,vector<vector<string>>& res){
        if(row == n){
            res.push_back(board);
            return true;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                backtrack(board,row + 1,n,res);
                board[row][col] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;        
        string row(n,'.');
        vector<string> board(n,row);
        backtrack(board,0,n,res);
        return res;
    }
};
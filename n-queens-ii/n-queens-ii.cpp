class Solution {
public:
    int ans = 0;
    bool isValid(vector<string> board,int row,int col,int n){
        for(int i = 0; i < n; i++)
            if(board[i][col] == 'Q')
                return false;
        for(int i = row,j = col; i >= 0 and j >= 0; i--,j--)
            if(board[i][j] == 'Q')
                return false;
        for(int i = row,j = col; i >= 0 and j < n; i--,j++)
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    void backtrack(vector<string> board,int row,int n){
        if(row == n){
            ans++;
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(board,row,col,n)){
                board[row][col] = 'Q';
                backtrack(board,row+1,n);
                board[row][col] = '.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        string row(n,'.');
        vector<string> board(n,row);
        backtrack(board,0,n);
        return ans;
    }
};
class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    TicTacToe(int n) {
        board = vector<vector<int>>(n,vector<int>(n,0));
        this->n = n;
    }
    bool checkRow(int row,int player){
        for(int i = 0; i < n; i++){
            if(board[row][i] != player)
                return false;
        }
        return true;
    }
    bool checkDiagonal(int player){
        for(int i = 0; i < n; i++){
            if(board[i][i] != player)
                return false;
        }
        return true;
    }
    bool checkAntiDiagonal(int player){
        for(int i = 0; i < n; i++){
            if(board[i][n - i - 1] != player)
                return false;
        }
        return true;
    }
    bool checkCol(int col,int player){
        for(int i = 0; i < n; i++){
            if(board[i][col] != player){
                return false;
            }
        }
        return true;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        bool won = checkCol(col,player) or checkRow(row,player) or checkDiagonal(player) or checkAntiDiagonal(player);
        if(won)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
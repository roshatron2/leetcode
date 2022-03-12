class TicTacToe {
public:
    vector<int> rows,cols;
    int diagonal = 0,antiDiagonal = 0;
    int n;
    TicTacToe(int n) {
        rows.assign(n,0);
        cols.assign(n,0);
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        int score = player == 1 ? 1 : -1;
        cols[col] += score;
        rows[row] += score;
        if(row == col){
            diagonal += score;
        }
        if(col == n - row - 1){
            antiDiagonal += score;
        }
        if(abs(cols[col]) == n 
           or abs(rows[row]) == n 
           or abs(diagonal) == n 
           or abs(antiDiagonal) == n){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
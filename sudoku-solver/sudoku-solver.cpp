class Solution {
    int rows[9][10] = {0};
    int cols[9][10] = {0};
    int blocks[3][3][10] = {0};
public:
    bool isValid(vector<vector<char>> board,int i,int j,char c) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[3][3][9] = {0};
        board[i][j] = c;
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c]=='.')continue;
                int num = board[r][c]-'1';
                if(cols[c][num]++ || rows[r][num]++ || blocks[r/3][c/3][num]++)
                    return false;
            }
        } 
        return true;
    }
    bool backtrack(vector<vector<char>>& board,int i,int j){
        if(i == 9)
            return true;
        if(j == 9)
            return backtrack(board,i+1,0);
        if(board[i][j] != '.') 
            return backtrack(board,i,j+1);
        for(char c = '1'; c <= '9'; c++){
            if(isValid(board,i,j,c)){
                board[i][j] = c; 
                int num = c - '0';
                rows[i][num] = 1; cols[j][num] = 1; blocks[i/3][j/3][num] = 1;
                if(backtrack(board,i,j+1)){
                    return true;
                }
                board[i][j] = '.';
                rows[i][num] = 0;cols[j][num] = 0;blocks[i/3][j/3][num] = 0;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0;j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    rows[i][num] = 1; cols[j][num] = 1; blocks[i/3][j/3][num] = 1;
                }
            }
        }
        backtrack(board,0,0);
    }
};
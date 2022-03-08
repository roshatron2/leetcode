class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> duplicateBoard(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighbors = 0;
                for(auto dir : directions){
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(x >= 0 and y >= 0 and x < m and y < n and board[x][y] == 1){
                        neighbors++;
                    }
                }
                if(board[i][j] and neighbors < 2){
                    duplicateBoard[i][j] = 0;
                }
                if(board[i][j] and neighbors == 2 or neighbors == 3){
                    duplicateBoard[i][j] = 1;
                }
                if(board[i][j] and neighbors > 3){
                    duplicateBoard[i][j] = 0;
                }
                if(board[i][j] == 0 and neighbors == 3){
                    duplicateBoard[i][j] = 1;
                }
            }
        }
        board = duplicateBoard;
    }
};

//count - neighbor count
//matrix[i][j] == 0 if count(i,j) < 2
//matrix[i][j] = 1 if count(i,j) x == 2 or x == 3
//matrix[i][j] = 0 if x > 3
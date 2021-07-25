class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char cur = board[i][j];
                if(board[i][j] == '.'){
                    continue;
                }
                
                //check row
                for(int k = j + 1; k < 9; k++){
                    if(board[i][k] == cur)
                        return false;
                }
                
                //check col
                for(int k = i + 1;k < 9; k++){
                    if(board[k][j] == cur){
                        return false;
                    }
                }
                vector<int> rowmapEnd = {3,3,3,6,6,6,9,9,9};
                vector<int> colmapEnd = {3,3,3,6,6,6,9,9,9};
                vector<int> rowmapStart = {0,0,0,3,3,3,6,6,6};
                vector<int> colmapStart = {0,0,0,3,3,3,6,6,6};
                for(int row = rowmapStart[i]; row < rowmapEnd[i]; row++){
                    for(int col = colmapStart[j]; col < colmapEnd[j]; col++){
                        if(row == i and col == j){
                            continue;
                        }
                        if(board[row][col] == cur){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
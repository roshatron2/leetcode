class Solution {
public:
    //https://leetcode.com/problems/valid-sudoku/discuss/15616/My-12-lines-CC%2B%2B-solution-with-1-time-traversal-and-9x9x3-memory
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][10] = {0};
        int cols[9][10] = {0};
        int blocks[3][3][10] = {0};
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(rows[i][num] or cols[j][num] or blocks[i/3][j/3][num])
                        return false;
                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    blocks[i/3][j/3][num] = 1;
                }
            }
        }
        return true;
    }
};
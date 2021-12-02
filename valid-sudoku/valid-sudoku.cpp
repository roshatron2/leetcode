class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int map[3][3][10] = {0};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                char cur = board[i][j];
                if(cur == '.')
                    continue;
                for(int k = j + 1; k < 9; k++){
                    if(board[i][k] == cur)
                        return false;
                }
                for(int k = i + 1; k < 9; k++){
                    if(board[k][j] == cur){
                        return false;
                    }
                }
                if(map[i/3][j/3][cur - '0'])
                    return false;
                map[i/3][j/3][cur - '0']++;
            }
        }
        return true;
    }
};
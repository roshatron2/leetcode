class Solution {
public:
    bool found = false;
    string target_word;
    void dfs(vector<vector<char>>& board, string word, int i, int j, int pos){
        if(i < 0 or i == board.size() or j < 0 or j == board[0].size()){
            return;
        }
        if(board[i][j] == '.' or board[i][j] != word[pos]){
            return;
        }
        if(pos == word.size() - 1){
            found = true;
            return;
        }
        char cur = board[i][j];
        board[i][j] = '.';
        dfs(board, word, i + 1, j, pos + 1);
        dfs(board, word, i, j + 1, pos + 1);
        dfs(board, word, i - 1, j, pos + 1);
        dfs(board, word, i, j - 1, pos + 1);
        board[i][j] = cur;
    }
    bool exist(vector<vector<char>>& board, string word) {
        target_word = word;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, word, i, j, 0);
            }
        }
        return found;
    }
};
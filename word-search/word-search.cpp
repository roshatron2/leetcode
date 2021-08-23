class Solution {
public:
    bool backtrack(vector<vector<char>> &board,string word,int i,int j,int idx){
        if(word.size() == idx){
            return true;
        }
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size()){
            return false;
        }
        char cur = board[i][j];
        if(cur != word[idx])
            return false;
        board[i][j] = '*';
        bool found = backtrack(board,word,i+1,j,idx + 1) or 
                     backtrack(board,word,i,j+1,idx + 1) or 
                     backtrack(board,word,i-1,j,idx + 1) or 
                     backtrack(board,word,i,j-1,idx + 1);
        board[i][j] = cur;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int count = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(backtrack(board,word,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};
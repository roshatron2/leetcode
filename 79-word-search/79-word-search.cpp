class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int pos){
        if(pos == word.size())
            return true;
        if(i == -1 or i == board.size() or j == -1 or j == board[0].size())
            return false;
        if(board[i][j] != word[pos])
            return false;
        char temp = board[i][j];
        board[i][j] = '.';
        bool found = dfs(board,word,i,j + 1,pos + 1) or
                     dfs(board,word,i + 1,j,pos + 1) or
                     dfs(board,word,i - 1,j,pos + 1) or
                     dfs(board,word,i,j - 1,pos + 1);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board,word,i,j,0)) 
                    return true;
            }
        }
        return false;
    }
};
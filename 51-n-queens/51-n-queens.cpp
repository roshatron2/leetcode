class Solution {
public:
    int n;
    vector<vector<string>> res;
    bool isValid(vector<string> board,int i,int j){
        vector<vector<int>> dirs = {{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
        for(auto dir : dirs){
           int x = i,y = j;
           while(x < n and y < n and x >= 0 and y >= 0 and board[x][y] != 'Q'){
               x += dir[0];
               y += dir[1];
           }
           if(x < n and y < n and x >= 0 and y >= 0){
               return false;
           } 
        }
        return true;
    }
    void dfs(vector<string> board,int i){
        if(i == n){
            res.push_back(board);
            return; 
        }
        for(int j = 0; j < n; j++)
            if(isValid(board,i,j)){
                board[i][j] = 'Q';
                dfs(board,i + 1);
                board[i][j] = '.';
            }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n,string(n,'.'));
       this->n = n;
       dfs(board,0);
       return res;
    }
};
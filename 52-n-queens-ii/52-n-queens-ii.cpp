class Solution {
public:
    int solutions = 0,n;
    bool isValid(vector<string> &board,int i,int j){
       vector<vector<int>> dirs = {{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
       for(auto dir : dirs){
           int x = i,y = j;
           while(x >= 0 and y >= 0 and x < n and y < n and board[x][y] != 'Q'){
              x += dir[0];
              y += dir[1];
           }
           if(x >= 0 and y >= 0 and x < n and y < n){
               return false;
           }
       }
       return true;
    }
    void dfs(vector<string> board,int i){
       if(i == n){
           solutions++;
           return;
       }
       for(int j = 0; j < n; j++){
           if(isValid(board,i,j)){
               board[i][j] = 'Q';
               dfs(board,i + 1);
               board[i][j] = '.';
           }
       }
    }
    int totalNQueens(int n) {
       this->n = n;
       vector<string> board(n,string(n,'.'));
       dfs(board,0);
       return solutions;
    }
};
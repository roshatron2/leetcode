class Solution {
public:
    string s,t;
    int dp[501][501] = {0};
    int dfs(int i,int j){
       if(dp[i][j])
           return dp[i][j];
       if(i == s.size() and j == t.size()){
           return 0;
       } 
       if(i == s.size()){
           return dfs(i,j + 1) + 1;
       }
       if(j == t.size()){
           return dfs(i + 1,j) + 1;
       }
       if(s[i] == t[j]){
           return dfs(i + 1,j + 1);
       }
       return dp[i][j] = min(dfs(i + 1,j),dfs(i,j + 1)) + 1; 
    }
    int minDistance(string word1, string word2) {
        this->s = word1;
        this->t = word2;
        return dfs(0,0);
    }
};
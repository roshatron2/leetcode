class Solution {
public:
    int dfs(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i == s.size()){
            if(j == t.size()){
                return 1;
            } else {
                return 0;
            }
        }
        if(j == t.size()){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = dfs(i + 1, j + 1, s, t, dp) + dfs(i + 1, j, s, t, dp);
        }
        return dp[i][j] = dfs(i + 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
       vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
       return dfs(0, 0, s, t, dp); 
    }
};
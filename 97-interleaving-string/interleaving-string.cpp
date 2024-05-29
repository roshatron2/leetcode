class Solution {
public:
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3,
             vector<vector<vector<int>>>& dp) {
        if (k == s3.size()) {
            if (i == s1.size() and j == s2.size()) {
                return true;
            } else {
                return false;
            }
        }
        if (dp[k][i][j] != -1) {
            return dp[k][i][j];
        }
        if (s3[k] == s1[i] and s3[k] == s2[j]) {
            return dp[k][i][j] = dfs(i + 1, j, k + 1, s1, s2, s3, dp) or
                                 dfs(i, j + 1, k + 1, s1, s2, s3, dp);
        } else if (s3[k] == s2[j]) {
            return dp[k][i][j] = dfs(i, j + 1, k + 1, s1, s2, s3, dp);
        } else if (s3[k] == s1[i]) {
            return dp[k][i][j] = dfs(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        return dp[k][i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int o = s3.size();
        vector<vector<vector<int>>> dp(o + 1,vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, 0, 0, s1, s2, s3, dp);
    }
};
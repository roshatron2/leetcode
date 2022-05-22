class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        fill_n(*dp,n * n,0);
        int ans = 0;
        for(int i = 0; i < n; i++,ans++){
            dp[i][i] = 1;
        }
        for(int i = 0; i < n - 1; i++){
            dp[i][i + 1] = (s[i] == s[i + 1]);
            ans += dp[i][i + 1]; 
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0,j = i + len - 1; j < n; ++i,++j){
                dp[i][j] = dp[i + 1][j - 1] and (s[i] == s[j]);
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
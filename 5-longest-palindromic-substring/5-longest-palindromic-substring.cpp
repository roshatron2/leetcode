class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, len = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i == n - 1)
                break;
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (dp[i + 1][j - 1] or j - i == 1) {
                        dp[i][j] = 1;
                        if (j - i + 1 > len) {
                            len = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};
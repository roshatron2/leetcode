class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1001][1001] = {0};
        int n = s.size();
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        if(n == 1)
            return s;
        string ans = "";
        ans += s[0];
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    if(j - i == 1 or dp[i + 1][j - 1]){
                        dp[i][j] = 1;
                        if(ans.size() < j - i + 1)
                            ans = s.substr(i,j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};
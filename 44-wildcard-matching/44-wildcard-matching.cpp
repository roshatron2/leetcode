class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1,vector<bool>(p.size() + 1,false));
        dp[0][0] = true;
        for(int j = 1; j <= p.size(); j++){
            if(p[j-1] == '*')
                dp[0][j] = true;
            else
                break;
        }
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(p[j-1] != '*'){
                    dp[i][j] = dp[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '?'); 
                } else {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]; 
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
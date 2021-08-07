class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000][1000] = {0};
        if(s.empty()) return s;
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        string ans = "";
        ans += s[0];
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i + 1; j < s.size(); j++){
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
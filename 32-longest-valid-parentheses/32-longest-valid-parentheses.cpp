class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxans = 0;
        vector<int> dp(n,0);        
        for(int i = 1; i < n; i++){
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                } else if(i - dp[i - 1] - 1 >= 0 and s[i - 1] == ')' and s[i - dp[i - 1] - 1] == '('){ 
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;    
                }
                maxans = max(maxans,dp[i]);
            }
        }
        return maxans;
    }
};
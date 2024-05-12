class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        vector<bool> dp(s.size() + 1, false);    
        dp[0] = true;

        for(int i = 0; i <= s.size(); i++){
            for(string word : wordDict){
                int l = word.size();
                if(i - l >= 0){
                    if(s.substr(i - l, l) == word and dp[i - l]){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
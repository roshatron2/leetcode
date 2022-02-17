class Solution {
public:
    unordered_map<int,bool> map;
    bool dfs(string s,vector<string> words,int i){
        if(map.find(i) != map.end())
            return map[i];
        if(i == s.size()){
            return true;
        }
        for(string word : words){
            int j = 0;
            for(; j < word.size(); j++){
                if(s[i + j] != word[j])
                    break;
            }
            if(j == word.size()){
                return map[i] = dfs(s,words,i + j + 1);
            }
        }
        return map[i] = false;    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        for(int i = 0; i < s.size(); i++){
            if(dp[i]){
                for(string word : wordDict){
                    if(s.substr(i,word.size()) == word){
                        dp[i + word.size()] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
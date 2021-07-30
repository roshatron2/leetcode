class Solution {
public:
    unordered_map<string,vector<string>> memo;
    vector<string> dfs(string s,vector<string> words){
        if(memo[s].size() != 0)
            return memo[s];
        vector<string> res;
        if(s == ""){
            res.push_back("");
            return res;     
        }
        for(auto word : words){
            int idx = s.find(word);
            if(idx == 0){
                string suffix = s.substr(word.size());
                vector<string> ways = dfs(suffix,words);
                for(auto way : ways){
                    res.push_back(word + (!way.empty() ? " " : "") + way);
                }
            }
        }
        memo[s] = res;
        return memo[s];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return dfs(s,wordDict);
    }
};
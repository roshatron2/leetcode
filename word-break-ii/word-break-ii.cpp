class Solution {
public:
    vector<string> res;
    unordered_map<string,string> map;
    string dfs(string s,string comb, vector<string> words){
        if(s == ""){
            comb.pop_back();
            res.push_back(comb);
            return comb;    
        }
        for(auto word : words){
            int idx = s.find(word);
            if(idx == 0){
                string suffix = s.substr(word.size());
                dfs(suffix,comb + word + " ",words);
            }
        }
        return "";
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dfs(s,"",wordDict);
        return res;
    }
};
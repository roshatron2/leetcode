class Solution {
public:
    vector<vector<string>> res;
    bool isPal(string& s){
        int l = 0, r = s.size() - 1; 
        while(l < r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    bool isValid(vector<string>& words){
        for(string word : words){
            if(!isPal(word)){
                return false;
            }
        }
        return true;
    }
    void dfs(string& s, int i, vector<string> part) {
        if (i == s.size()) {
            if (isValid(part))
                res.push_back(part);
            return;
        }
        part.push_back(string(1, s[i]));
        dfs(s, i + 1, part);
        part.pop_back();
        if (!part.empty()) {
            string back = part.back();
            part.pop_back();
            part.push_back(back + s[i]);
            dfs(s, i + 1, part);
        }
    }
     
    vector<vector<string>> partition(string s) {
        dfs(s, 0, {});
        return res;
    }
};
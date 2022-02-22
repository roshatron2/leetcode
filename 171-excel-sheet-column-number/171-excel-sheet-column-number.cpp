class Solution {
public:
    long long dfs(string s){
        if(s.size() == 1){
            return s[0] - 'A' + 1;
        }
        return 26 * dfs(s.substr(0,s.size() - 1)) + s[s.size() - 1] - 'A' + 1;
    }    
    int titleToNumber(string s) {
        return dfs(s);
    }
};
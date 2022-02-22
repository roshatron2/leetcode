class Solution {
public:
    long long dfs(int n,string &s){
        if(n == 0)
            return s[n] - '@';
        return 26 * dfs(n-1,s) + s[n] - '@';
    }
    int titleToNumber(string s) {
        return dfs(s.size() - 1,s);
    }
};
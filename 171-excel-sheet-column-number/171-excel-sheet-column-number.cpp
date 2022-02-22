class Solution {
public:
    long long dfs(int n,string &s){
        if(n == 1){
            return s[n-1] - 'A' + 1;
        }
        return 26 * dfs(n-1,s) + s[n - 1] - 'A' + 1;
    }
    int titleToNumber(string s) {
        int n = s.size();
        return dfs(n,s);
    }
};
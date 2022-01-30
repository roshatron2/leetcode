class Solution {
public:
    int dfs(int m,int n,vector<vector<int>>& memo){
        if(memo[m][n])
            return memo[m][n];
        if(m == 0 or n == 0)
            return 0;
        if(m == 1 and n == 1)
            return 1;
        memo[m][n] = dfs(m-1,n,memo) + dfs(m,n-1,memo);
        return memo[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1,vector<int>(n + 1,0));
        return dfs(m,n,memo);
    }
};
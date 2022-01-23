class Solution {
public:
    unordered_map<int,int> map;
    int dfs(int n){
        if(map[n])
            return map[n];
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        map[n] = dfs(n-1) + dfs(n-2);
        return map[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 2,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
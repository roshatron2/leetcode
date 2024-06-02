class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int begin, int target, vector<int>& coins){
        if(target == 0){
            return 1;
        }
        if(dp[begin][target] != -1){
            return dp[begin][target];
        }
        int ways = 0;
        for(int i = begin; i < coins.size(); i++){
            if(target >= coins[i]){
                ways += dfs(i, target - coins[i], coins);
            }
        }
        return dp[begin][target] = ways;
    }
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins); 
    }
};
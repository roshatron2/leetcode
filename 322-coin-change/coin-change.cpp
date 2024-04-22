class Solution {
public:
    int dfs(int amount, int count, vector<int>& coins){
        if(amount == 0){
            return count;
        }
        if(amount < 0){
            return -1;
        }
        int total_count = INT_MAX;
        for(int coin : coins){
            int cur_count = dfs(amount - coin, count + 1, coins);
            if(cur_count > 0){
                total_count = min(total_count, cur_count);
            }
        }
        return total_count == INT_MAX ? -1 : total_count;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin >= 0 and dp[i - coin] != INT_MAX){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        } 
       return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
/*
0 1 2 3 4 5 6 7 8 9 10 11 12
0 1

*/
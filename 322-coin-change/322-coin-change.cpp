class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int coin : coins){
                if(i >= coin){
                    if(dp[i - coin] == -1)
                        continue;
                    dp[i] = min(dp[i],dp[i - coin] + 1);
                }
            }
            dp[i] = dp[i] == INT_MAX ? -1 : dp[i];
        }
        return dp[amount];
    }
};

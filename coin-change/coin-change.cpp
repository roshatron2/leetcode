class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,INT_MAX - 1);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int coin : coins){
                if(i >= coin){
                    dp[i] = min(dp[i - coin] + 1,dp[i]);
                }
            }
        }
        return dp[amount] != INT_MAX - 1 ? dp[amount] : -1;
    }
};
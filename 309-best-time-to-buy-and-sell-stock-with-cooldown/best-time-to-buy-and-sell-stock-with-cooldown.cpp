class Solution {
public:
    int dfs(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        if(buy){
            //buy == 1
            int bought = dfs(i + 1, !buy, prices, dp) - prices[i];
            int hold = dfs(i + 1, buy, prices, dp);
            return dp[i][buy] = max(bought, hold);
        }
        //buy == 0
        int sell = prices[i] + dfs(i + 2, !buy, prices, dp);
        int hold = dfs(i + 1, buy, prices, dp);
        return dp[i][buy] = max(sell, hold);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dfs(0, 1, prices, memo); 
    }
};
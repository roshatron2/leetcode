class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buyDay = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - prices[buyDay] > max_profit){
                max_profit = prices[i] - prices[buyDay];
            } 
            if(prices[i] < prices[buyDay]){
                buyDay = i;
            }
        }
        return max_profit;
    }
};

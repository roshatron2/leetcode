class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = 0,profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[day]){
                day = i;
            }
            profit = max(profit,prices[i] - prices[day]);
        }
        return profit;
        
    }
};
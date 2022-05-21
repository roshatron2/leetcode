class Solution {
public:
    vector<int> coins;
    unordered_map<int,int> map;
    int dfs(int amount){
       if(amount < 0){
           return -1;
       }
       if(map[amount])
           return map[amount];
       if(amount == 0)
           return 0;
       int minCount = INT_MAX;
       for(int coin : coins){
          int count = dfs(amount - coin); 
          if(count == -1)
              continue;
          minCount = min(count,minCount);
       } 
       map[amount] = minCount == INT_MAX ? -1 : minCount + 1;
       return map[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        return dfs(amount);
    }
};
        

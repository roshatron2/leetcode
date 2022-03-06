class Solution {
public:
    int ans = 0;
    int mod = 1e9 + 7;
    vector<vector<int>> memo;
    long totalWays(int unpicked,int undelivered){
        if(unpicked == 0 and undelivered == 0)
            return 1;
        if(unpicked < 0 or undelivered < 0 or undelivered < unpicked){
            return 0;
        }
        if(memo[unpicked][undelivered])
            return memo[unpicked][undelivered];
        long ans = 0;
        ans += unpicked * totalWays(unpicked - 1,undelivered);
        ans %= mod;
        ans += (undelivered - unpicked) * totalWays(unpicked,undelivered - 1);
        ans %= mod;
        return memo[unpicked][undelivered] = ans;
    }
    int countOrders(int n) {
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, 0));
        return totalWays(n,n);
    }
};
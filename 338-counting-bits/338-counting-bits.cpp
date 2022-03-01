class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1,0);
        if(n == 0)
            return dp;
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int x = pow(2,floor(log2(i)));
            if(x == i)
                dp[i] = 1;
             else 
                dp[i] = 1 + dp[i - x];
        }
        return dp;
    }
};

 
    
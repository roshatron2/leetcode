class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1,0);
        if(n == 0) 
            return {0};
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 0; i <= n; i++){
            if(floor(log2(i)) == log2(i) and i != 0){
                dp[i] = 1;
            }
            else {
                int x = pow(2,floor(log2(i)));
                dp[i] = dp[x] + dp[i-x];
            }
        }
        return dp;
    }
};
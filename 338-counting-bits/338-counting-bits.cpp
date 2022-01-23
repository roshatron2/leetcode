class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 2,0);
        vector<int> res;
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 0; i <= n; i++){
            if(floor(log2(i)) == log2(i) and i != 0){
                dp[i] = 1;
                res.push_back(dp[i]);
            }
            else {
                int x = pow(2,floor(log2(i)));
                dp[i] = dp[x] + dp[i-x];
                res.push_back(dp[i]);
            }
        }
        return res;
    }
};
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i <= n; i++){
            int sr = sqrt(i);
            if(sr * sr == i)
                squares.push_back(i);
        }
        vector<int> dp(n + 1,n);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            for(int k : squares){
                if(i < k)
                    break;
                dp[i] = min(dp[i],dp[i - k] + 1);
            }
        }
        return dp[n];
    }
};
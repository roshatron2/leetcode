class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0'){
            return 0;
        }
        vector<int> dp(n + 1, 0); 
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int first = stoi(s.substr(i - 1, 1));
            int second = stoi(s.substr(i - 2, 2));
            if(first >= 1 and first <= 9){
                dp[i] = dp[i - 1];
            }
            if(second >= 10 and second <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
/*
  2 2 6
0 1 2 3
1 1 2 3 
1 0 9
0 1 2 3
1 1 2 
*/
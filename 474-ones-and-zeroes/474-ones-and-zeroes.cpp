class Solution {
public:
    //int dp[601][101][101] = {0};
    vector<int> countFun(string s){
       int ones = 0,zeroes = 0;
       for(char i : s){
           if(i == '0'){
               zeroes++;
           } else {
               ones++;
           }
       }
       return {zeroes,ones};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101] = {0};
        for(string s : strs){
            vector<int> count = countFun(s);
            for(int zeroes = m; zeroes >= count[0]; zeroes--){
               for(int ones = n; ones >= count[1]; ones--){
                   dp[zeroes][ones] = max(1 + dp[zeroes - count[0]][ones - count[1]],dp[zeroes][ones]);
               } 
            }
        }  
        return dp[m][n];
    }
};
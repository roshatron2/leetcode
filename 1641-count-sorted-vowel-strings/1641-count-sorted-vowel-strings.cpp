class Solution {
public:
    int dp[51][51] = {0};
    int dfs(int n,int vowels){
        if(dp[n][vowels]){
            return dp[n][vowels];
        } 
        if(n == 1){
            return vowels;
        }
        if(vowels == 1){
            return 1;
        }
        return dp[n][vowels] = dfs(n - 1,vowels) + dfs(n,vowels - 1);
    }
    int countVowelStrings(int n) {
        return dfs(n,5);        
    }
};
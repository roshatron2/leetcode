class Solution {
public:
    unordered_map<int,int> map;
    int deleteAndEarn(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i : nums){
            map[i]++;
            mx = max(mx,i);
        }
        vector<int> dp(mx + 1,0);
        dp[0] = 0;
        dp[1] = map[1];
        for(int i = 2; i <= mx; i++){
            int gain = map[i] * i;
            dp[i] = max(dp[i - 1],dp[i - 2] + gain);
        }
        return dp[mx];
    }
};
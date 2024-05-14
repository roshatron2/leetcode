class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1){
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int cur = nums[i - 1];       
                if(j < cur){
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - cur];
                }
            }
        }
        return dp[n][target];
    }
};
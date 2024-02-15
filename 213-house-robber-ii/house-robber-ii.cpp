class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = dp[0];
        for(int i = 2; i < n - 1; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int rob_first = dp[n - 2];
        dp = vector<int>(n, 0);
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int rob_last = dp[n - 1]; 
        return max(rob_first, rob_last);
    }
};
/*
0 1 2 3 4
2 3 2 

rf = true;
dp
0 1 2 3
1 2 4 6 
*/
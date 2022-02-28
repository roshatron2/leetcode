class Solution {
public:
    unordered_map<int,int> map;
    int dfs(vector<int> nums,int pos){
        if(map.find(pos) != map.end()){
            return map[pos];
        }
        if(pos >= nums.size()){
            return 0;
        }
        map[pos] = max(dfs(nums,pos + 1),dfs(nums,pos + 2) + nums[pos]);
        return map[pos];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};


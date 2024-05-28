class Solution {
public:
    unordered_map<string,int> memo;
    int dfs(int i, int target, vector<int>& nums){
        string key = to_string(i) + "," + to_string(target);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }
        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        int add = dfs(i + 1, target - nums[i], nums);
        int sub = dfs(i + 1, target + nums[i], nums);
        return memo[key] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dfs(0, target, nums); 
    }
};
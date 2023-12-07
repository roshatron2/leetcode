class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int k){
        if(k == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = k; i < nums.size(); i++){
            swap(nums[k], nums[i]);
            dfs(nums, k + 1);
            swap(nums[k], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res; 
    }
};
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &nums,int begin){
        if(begin == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin],nums[i]);
            dfs(nums,begin + 1);
            swap(nums[begin],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }
};
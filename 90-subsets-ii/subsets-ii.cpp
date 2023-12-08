class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int begin, vector<int> cur){
        res.push_back(cur);
        for(int i = begin; i < nums.size(); i++){
            cur.push_back(nums[i]);
            if(i == begin or nums[i] != nums[i - 1]){
                dfs(nums, i + 1, cur);
            }
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, {});
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int begin,vector<int> nums){
        if(begin == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            swap(nums[i],nums[begin]);
            backtrack(begin + 1,nums);
            swap(nums[i],nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0,nums);
        return res;
    }
};
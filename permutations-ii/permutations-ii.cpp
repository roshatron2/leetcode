class Solution {
public:
    vector<vector<int>> res;
    void permute(vector<int> nums,int begin){
        if(begin == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            if(nums[i] == nums[begin] and i != begin)
                continue;
            swap(nums[i],nums[begin]);
            permute(nums,begin + 1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        permute(nums,0);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> nums,int start){
       if(start == nums.size() - 1){
          res.push_back(nums);
          return;
       }
       for(int i = start; i < nums.size(); i++){
           if(nums[i] == nums[start] and i != start)
               continue;
           swap(nums[start],nums[i]);
           dfs(nums,start + 1);
           //swap(nums[start],nums[i]);
       }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }
};
/*
                            [1,1,2]
            
         [1,1,2]            [1,1,2]X          [2,1,1]
                     
    [1,1,2]   [1,2,1]  [1,1,2]   [1,2,1] [2,1,1]    [2,1,1]X

*/
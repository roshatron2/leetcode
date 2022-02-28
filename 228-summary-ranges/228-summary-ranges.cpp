class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if(i + 1 < nums.size() and nums[i] == nums[i + 1] - 1){
                continue;
            } else if(i == j){
                res.push_back(to_string(nums[i])); 
            } else {
                res.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
            }
            j = i + 1;
        }
        return res;
    }
};
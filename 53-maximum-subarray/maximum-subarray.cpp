class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;    
        int max_sum = nums[0];

        for(int i = 0; i < nums.size(); i++){
            cur = max(nums[i], cur + nums[i]) ;
            max_sum = max(max_sum, cur);
        }
        return max_sum;
    }
};
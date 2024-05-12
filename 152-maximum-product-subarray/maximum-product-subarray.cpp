class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = *max_element(nums.begin(), nums.end()); 
        int cur_max = 1;
        int cur_min = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cur_max = 1; 
                cur_min = 1;
            }
            int tmp = cur_max;
            cur_max = max({nums[i] * cur_max, nums[i] * cur_min, nums[i]});
            cur_min = min({nums[i] * tmp, nums[i] * cur_min, nums[i]});
            max_prod = max(max_prod, cur_max); 
        }
        return max_prod;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int pre = nums[0],cur = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int tmp = cur;
            cur = max(pre + nums[i],cur);
            pre = tmp;
        }
        return cur;
    }
};


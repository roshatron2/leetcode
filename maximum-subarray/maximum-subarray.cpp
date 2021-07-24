class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0],mx = cur;
        for(int i = 1; i < nums.size(); i++){
            cur = max(cur + nums[i],nums[i]);
            mx = max(mx,cur);
        }
        return mx;
    }
};
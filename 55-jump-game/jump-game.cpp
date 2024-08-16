class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }
        if(nums[0] == 0){
            return false;
        }
        int max_reach = nums[0];
        for(int i = 1; i < n and i <= max_reach; i++){
            max_reach = max(max_reach, i + nums[i]);
        }
        return max_reach >= n - 1;
    }
};

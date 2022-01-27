class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int &i : nums){
            if(i <= 0) i = n + 1;
        }
        for(int i = 0; i < n; i++){
            int j = abs(nums[i]) - 1;
            if(j >= n)
                continue;
            if(nums[j] > 0)
                nums[j] *= -1;
        }
        for(int i = 1; i <= n; i++){
            if(nums[i-1] > 0)
                return i;
        }
        return n + 1;
    }
};
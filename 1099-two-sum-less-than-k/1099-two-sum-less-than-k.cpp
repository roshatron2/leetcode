class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maxSum = -1;
        sort(nums.begin(),nums.end());
        int i = 0,j = nums.size() - 1;
        while(i < j){
            int curSum = nums[i] + nums[j];
            if(curSum < k){
                maxSum = max(maxSum,curSum);
                i++;
            } else {
               j--; 
            }
        }
        return maxSum;
    }
};
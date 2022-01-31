class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0,i = 0,k = nums.size() - 1;
        
        while(j <= k){
            if(nums[j] < 1){
                swap(nums[i],nums[j]);
                i++;
                j++;
            } else if(nums[j] > 1){
                swap(nums[k],nums[j]);
                k--;
            } else {
                j++;
            }
        }
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return;
        int i = n - 2;
        while (i >= 0 and nums[i] >= nums[i + 1]) {
            i--;
        }
        int j = n - 1;
        if(i >= 0){ 
            for(j = n - 1; nums[j] <= nums[i]; j--);
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin() + i + 1,nums.end()); 
    }
};
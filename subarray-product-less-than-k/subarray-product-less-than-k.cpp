class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1,count = 0,j = 0;
        if(k <= 1) return 0;
        for(int i = 0; i < nums.size(); i++){
            product *= nums[i];
            while(product >= k){
                product /= nums[j++];
            }
            count += i - j + 1;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size()),left;
        int prod = 1;
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            left.push_back(prod);
        }
        prod = 1;
        int j = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            prod *= nums[i];
            right[j--] = prod;
        }
        nums[0] = right[1];
        nums[nums.size() - 1] = left[nums.size() - 2];
        for(int i = 1; i < nums.size() - 1; i++){
            nums[i] = left[i-1] * right[i+1];
        }
        return nums;
    }
};
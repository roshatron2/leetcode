class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n),right(n),res(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for(int i = 1; i < nums.size(); i++){
           left[i] = nums[i] * left[i - 1];
           right[n - i - 1] = nums[n - i - 1] * right[n - i];
        }
        for(int i = 0; i < n; i++){
           if(i == 0){
               res[i] = right[i + 1];
           } else if(i == n - 1){
               res[i] = left[i - 1];
           } else 
               res[i] = left[i - 1] * right[i + 1];
        }
        return res;
    }
};



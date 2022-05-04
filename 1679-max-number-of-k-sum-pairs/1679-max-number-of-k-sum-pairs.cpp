class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops = 0;
        sort(nums.begin(),nums.end());
        int l = 0,r = nums.size() - 1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum < k){
                l++;
            } else if(sum > k){
               r--; 
            } else {
                ops++;
                l++;
                r--;
            }
        }
        return ops;
    }
};
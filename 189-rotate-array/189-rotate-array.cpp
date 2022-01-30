class Solution {
public:
    void reverse(int l,int r,vector<int> &nums){
        int n =  nums.size();
        while(l < r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(0,n - k - 1,nums);
        reverse(n - k,n - 1,nums);
        reverse(0,n-1,nums);
    }
};

class Solution {
public:
    void reverse(vector<int> &nums,int l,int r){
        while(l <= r){
            swap(nums[l++],nums[r--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n - k - 1);
        reverse(nums,n - k,n - 1);
        reverse(nums,0,n - 1);
    }
};

// 1 2 3 4 5 6 7
//4 3 2 1 7 6 5
//5 6 7 1 2 3 4
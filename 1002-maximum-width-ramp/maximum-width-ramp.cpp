class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n, nums[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(nums[i], rightMax[i + 1]);
        }
        int l = 0; 
        int r = 0;
        int width = 0;
        while(r < n){
            while(l < r and nums[l] > rightMax[r]){
                l++;
            }
            width = max(width, r - l);
            r++;
        }
        return width;
    }
};
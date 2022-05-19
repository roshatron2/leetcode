class Solution {
public:
    int findMin(vector<int>& nums) {
        int minEle = INT_MAX;
        int l = 0,r = nums.size() - 1;
        int pivot;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[0] <= nums[mid]){
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        return r + 1 < nums.size() ? nums[r + 1] : nums[0];
    }
};
/*
 0 1 2 3 4 
[3,4,5,1,2]
l - 3
r - 2
mid = 3
 0 1 2 3 4 5 6
[4,5,6,7,0,1,2]
l - 4
r - 3
mid - 3 5 4

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,n = nums.size(),r = n - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[0] <= nums[mid]){
               if(nums[l] <= target and target <= nums[mid]){
                   r = mid - 1;
               } else {
                   l = mid + 1;
               }
            } else {
               if(nums[mid] <= target and target <= nums[r]){
                  l = mid + 1; 
               } else {
                   r = mid - 1;
               } 
            }
        }
        return -1;
    }
};
/*
 0 1 2 3 4 5 6
[4,5,6,7,0,1,2]
l = 4
r = 4
mid = 5
target = 0
1 <= 0 and 0 <= 2 
*/
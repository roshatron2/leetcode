class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(target > nums[mid]){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
//0 1 2 3
//1 3 5 6
//l 0 1
//r 3 0
//mid 1

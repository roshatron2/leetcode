class Solution {
public:
    int lower_bound(vector<int> nums,int target){
       int l = 0,r = nums.size() - 1,mid = -1;
       while(l <= r){
           mid = (l + r) >> 1;
           if(nums[mid] == target){
                if(mid > 0 and nums[mid-1] == target)
                    r  = mid - 1;
                else
                    return mid;
           } else if(nums[mid] > target){
               r = mid - 1;
           } else {
               l = mid + 1;
           }
       }
       return -1; 
    }
    int upper_bound(vector<int> nums,int target){
        int l = 0,r = nums.size() - 1,mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(nums[mid] == target){
                if(mid + 1 < nums.size() and nums[mid + 1] == target){
                    l = mid + 1;
                } else {
                    return mid;
                }
                
            } else if(nums[mid] > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums,target),upper_bound(nums,target)};
    }
};
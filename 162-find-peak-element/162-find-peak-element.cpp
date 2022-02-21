class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(),mid;
        int l = 0,r = n - 1;
        while(l <= r){
            mid = (l + r) >> 1;
            if(mid - 1 >= 0 and mid + 1 < nums.size() and
               nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(mid + 1 < n and nums[mid] < nums[mid + 1]){
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        return mid;  
    }
};
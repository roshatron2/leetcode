class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        vector<int> nums;
        for(auto i : nums1){
            nums.push_back(i);
        }
        for(auto i : nums2){
            nums.push_back(i);
        }
        sort(nums.begin(),nums.end());
        if(nums.size() % 2 == 1){
            int i = (nums.size() + 1) / 2;
            return nums[i-1];
        } else {
            int mid = nums.size() / 2;
            return (double)(nums[mid] + nums[mid-1]) / 2;
        }
    }
};
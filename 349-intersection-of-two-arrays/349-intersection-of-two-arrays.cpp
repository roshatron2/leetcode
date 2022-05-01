class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0, j = 0,n1 = nums1.size(),n2 = nums2.size();
        vector<int> res;
        while(i < n1 and j < n2){
            if(nums1[i] < nums2[j]){
                i++;
            } else if(nums1[i] > nums2[j]){
                j++;
            } else {
                res.push_back(nums1[i]);
                i++;
                j++;
                while(i < n1 and nums1[i] == nums1[i - 1]){
                    i++;
                }
                while(j < n2 and nums2[j] == nums2[j - 1]){
                    j++;
                }
            }    
        }
        return res;
    }
};
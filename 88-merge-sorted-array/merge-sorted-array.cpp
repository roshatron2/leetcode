class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        if(m == 0)
            nums1 = nums2;
        while(i >= 0 and j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[k] = nums2[j];
                k--;
                j--;
            } else {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        while(i >= 0){
            nums1[k--] = nums1[i--];
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};
/*
i = 3;
j = 3
0 1 2 3 4 5
1 2 3 0 0 0
2 5 6

#test case 2
i = 0
j = 0
0 
0
1
*/
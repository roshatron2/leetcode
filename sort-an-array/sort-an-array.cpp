class Solution {
public:
    void merge(int l,int mid,int r,vector<int> &nums){
        int L = mid - l + 1;
        int R = r - mid;
        int left[L],right[R];
        
        for(int i = 0; i < L; i++){
            left[i] = nums[l + i];
        }
        for(int i = 0; i < R; i++){
            right[i] = nums[mid + 1 + i];
        }
        int i = 0,j = 0,k = l;
        while(i < L and j < R){
            if(left[i] <= right[j]){
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }
        while(i < L){
            nums[k++] = left[i++];
        }
        while(j < R){
            nums[k++] = right[j++];
        }
    }
    void mergeSort(int l,int r,vector<int> &nums){
        if(l == r){
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size() - 1,nums);
        return nums;
    }
};
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0,r = n - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(mid == 0 or arr[mid] < arr[mid+1]){
                l = mid + 1;
            }
            else if(mid == n - 1 or arr[mid] < arr[mid-1]){
                r = mid - 1;
            }
            else if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]){
                return mid;
            }
        }
        return -1;
    }
};
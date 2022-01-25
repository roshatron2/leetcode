class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0,n = arr.size(),j = n - 1;
        
        while(i + 1 < n and arr[i] < arr[i+1]){
            i++;
        }
        while(j - 1 >= 0 and arr[j-1] > arr[j]){
            j--;
        }
        if(i == 0 or j == n - 1)
            return false;
        
        return i == j;
    }
};
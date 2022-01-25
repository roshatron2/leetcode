class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0,n = arr.size(),j = n - 1;
        if(n == 1)
            return false;
        
        while(i + 1 < n and arr[i] < arr[i+1]){
            i++;
        }
        if(i == 0)
            return false;
        while(j - 1 >= 0 and arr[j-1] > arr[j]){
            j--;
        }
        if(j == n - 1)
            return false;
        
        return i == j;
    }
};
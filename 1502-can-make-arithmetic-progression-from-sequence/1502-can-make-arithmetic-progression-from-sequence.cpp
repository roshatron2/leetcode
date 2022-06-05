class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i = 1; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] != arr[i] - arr[i - 1]){
                return false;            
            }
        }
        return true;
    }
};
/*
0 1 2
1 3 5
*/
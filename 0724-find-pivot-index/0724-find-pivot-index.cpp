class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> prefix(n + 1,0);
        prefix[n - 1] = nums[n - 1]; 
        
        for(int i = n - 2; i >= 0; i--){
            prefix[i] = nums[i] + prefix[i + 1];
        }
        for(int i = 0; i < nums.size(); i++){
           if(sum == prefix[i + 1]){
              return i; 
           }
           sum += nums[i]; 
        }
        return -1;
    }
};
/*
0 1 2 3 4 5
1 7 3 6 5 6

prefix
0   1  2  3  4 5
28 27 20 17 11 6
i = 3
sum = 11;
*/
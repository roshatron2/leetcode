class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();    
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n - i; j++){
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }  
        }
        return nums[0];
    }
};
/*
0 : 1 2 3 4 5
1 : 3 5 7 9
2: 8 2 6
3: 0 8
4: 8
*/
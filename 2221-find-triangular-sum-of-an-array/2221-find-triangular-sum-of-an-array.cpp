class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();    
        vector<vector<int>> mat(n,vector<int>(n,0));
        mat[0] = nums;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n - i; j++){
                mat[i][j] = (mat[i - 1][j] + mat[i - 1][j + 1]) % 10;
            }  
        }
        return mat[n - 1][0];
    }
};
/*
0 : 1 2 3 4 5
1 : 3 5 7 9
2: 8 2 6
3: 0 8
4: 8
*/
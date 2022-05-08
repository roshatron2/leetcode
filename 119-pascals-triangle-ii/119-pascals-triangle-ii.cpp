class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> mat(rowIndex + 1,vector<int>(rowIndex + 1,1));
            
        for(int i = 2; i <= rowIndex; i++){
            for(int j = 1; j < i; j++){
                mat[i][j] = mat[i - 1][j]  + mat[i - 1][j - 1]; 
            }    
        }
        return mat[rowIndex];
    }
};
/*
    0 1 2
0 : 1
1 : 1 1
2 : 1 2 1
*/
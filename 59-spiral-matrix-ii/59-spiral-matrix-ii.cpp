class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startRow = 0,startCol = 0,endRow = n - 1,endCol = n - 1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int k = 1;
        while(startRow <= endRow and startCol <= endCol){
            for(int j = startCol; j <= endCol; j++){
                matrix[startRow][j] = k++;
            }
            startRow++;
            for(int i = startRow; i <= endRow; i++){
                matrix[i][endCol] = k++;
            }
            endCol--;
            for(int j = endCol; j >= startCol; j--){
                matrix[endRow][j] = k++;
            }
            endRow--;
            for(int i = endRow; i >= startRow; i--){
                matrix[i][startCol] = k++;
            }
            startCol++;
        }
        return matrix;
    }
};
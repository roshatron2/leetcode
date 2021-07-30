class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row,col;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(auto x : row){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[x][i] = 0;
            }
        }
        for(auto x : col){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][x] = 0;
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] > 0){
                    int top = i - 1 >= 0 ? mat[i - 1][j] : INT_MAX - 10;
                    int left = j - 1 >= 0 ? mat[i][j - 1] : INT_MAX - 10;
                    mat[i][j] = min(top,left) + 1;
                }
            }
        }
        for(int i = mat.size() - 1; i >= 0; i--){
            for(int j = mat[0].size() - 1; j >= 0; j--){
                if(mat[i][j] > 0){
                    int bottom = i + 1 < mat.size() ? mat[i + 1][j] : mat[i][j];
                    int right = j + 1 < mat[0].size() ? mat[i][j + 1] : mat[i][j];
                    mat[i][j] = min(mat[i][j],min(bottom + 1,right + 1));
                }
            }
        }
        return mat;
    }
};
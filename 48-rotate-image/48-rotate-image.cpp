class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix[0].size(); j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }      
        for(auto &row : matrix){
            reverse(row.begin(),row.end());
        }
    }
};
/*
1 4 7
2 5 8 
3 6 9

1 4 7
2 5 8
3 6 9
*/
class NumMatrix {
public:
    vector<vector<int>> matrix;
    unordered_map<int,vector<int>> map;
    NumMatrix(vector<vector<int>>& matrix) {
       this->matrix = matrix; 
       for(int i = 0; i < matrix.size(); i++){
           int sum = 0;
           for(int j = 0; j < matrix[0].size(); j++){
               sum += matrix[i][j];
               map[i].push_back(sum);
           }
       } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       int sum = 0;
       for(int i = row1; i <= row2; i++){
          sum += col1 >= 1 ? map[i][col2] - map[i][col1 - 1] : map[i][col2]; 
       } 
       return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
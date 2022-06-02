class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        for(int i = 0; i < matrix[0].size(); i++){
            vector<int> col;
            for(int j = 0; j < matrix.size(); j++){
               col.push_back(matrix[j][i]); 
            } 
            res.push_back(col);
        }    
        return res;
    }
};
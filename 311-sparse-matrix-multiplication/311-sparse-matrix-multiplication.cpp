class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> compress(vector<vector<int>> mat){
        unordered_map<int,vector<pair<int,int>>> map;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j])
                    map[i].push_back({mat[i][j],j});
            }
        }
        return map;
    }
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        unordered_map<int,vector<pair<int,int>>> A = compress(mat1);
        unordered_map<int,vector<pair<int,int>>> B = compress(mat2);
        
        int m = mat1.size(),k = mat1[0].size(),n = mat2[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        
        for(int mat1Row = 0; mat1Row < m; mat1Row++){
            for(auto [element1,mat1Col] : A[mat1Row]){
                for(auto [element2,mat2Col] : B[mat1Col]){
                   mat[mat1Row][mat2Col] += element1 * element2; 
                }
            }
        }
        return mat;
    }
};
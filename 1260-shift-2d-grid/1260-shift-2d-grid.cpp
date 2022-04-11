class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> vec;
        for(vector<int> row : grid){
            for(int i : row){
                vec.push_back(i);
            }
        }
        
        int len = vec.size();
        k = k % len;
        reverse(vec.begin(),vec.begin() + len - k);
        reverse(vec.begin() + len - k,vec.end());
        reverse(vec.begin(),vec.end());
        
        int pos = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0;j < grid[0].size(); j++){
                grid[i][j] = vec[pos++];
            }
        }
        return grid;
    }
};

/*
1 2 3 4 5 6 7 8 9
8 7 6 5 4 3 2 1 9
9 1 2 3 4 5 6 7 8
*/
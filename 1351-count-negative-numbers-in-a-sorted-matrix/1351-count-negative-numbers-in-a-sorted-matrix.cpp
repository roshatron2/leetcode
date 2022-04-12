class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i = 0,j = grid[0].size() - 1,count = 0,n = grid[0].size();
        while(i < grid.size()){
            while(j >= 0 and grid[i][j] < 0) j--;
            count += n - j - 1;
            i++;
        }
        return count;
    }
};
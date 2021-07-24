class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int l = 0,r = n - 1;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            if(matrix[mid][0] > target){
                r = mid - 1;
            } else if(matrix[mid].back() < target){
                l = mid + 1;
            } else {
                return binary_search(matrix[mid].begin(),matrix[mid].end(),target);
            }
        }
        return false;
    }
};
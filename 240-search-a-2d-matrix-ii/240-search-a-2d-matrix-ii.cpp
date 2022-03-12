class Solution {
public:
    bool binarySearch(vector<vector<int>> &matrix,int start,int target,bool isVertical){
        int l = start;
        int r = isVertical ? matrix.size() - 1 : matrix[0].size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isVertical ? matrix[mid][start] == target : matrix[start][mid] == target){
                return true;
            } else if(isVertical ? target < matrix[mid][start] : target < matrix[start][mid]){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int shorterDim = min(matrix.size(),matrix[0].size());
        for(int i = 0; i < shorterDim; i++){
            bool verticalFound = binarySearch(matrix,i,target,true);
            bool horizontalFound = binarySearch(matrix,i,target,false);
            if(verticalFound or horizontalFound){
                return true;
            }
        }
        return false;
    }
};
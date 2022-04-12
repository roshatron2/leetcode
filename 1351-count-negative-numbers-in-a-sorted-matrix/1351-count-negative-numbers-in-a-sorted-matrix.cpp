class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0,n = grid[0].size();
        for(vector<int> row : grid){
            int l = 0,r = n - 1,minIdx = n;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(row[mid] < 0){
                    r = mid - 1;
                    minIdx = min(minIdx,mid);
                } else {
                    l = mid + 1;
                }
            }
            count += n - minIdx;
        }
        return count;
    }
};

/*
4 3 2 -1
minIdx - 3
l - 3
r - 3
mid = 1 2 3

*/
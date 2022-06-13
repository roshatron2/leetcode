class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); 
        vector<int> cur,belowRow = triangle.back();
        for(int i = n - 2; i >= 0; i--){
            cur = {};
            for(int j = 0; j <= i; j++){
                int smallestBelow = min(belowRow[j],belowRow[j + 1]);        
                cur.push_back(smallestBelow + triangle[i][j]);
            }
            belowRow = cur;
        } 
        return belowRow[0];
    }
};
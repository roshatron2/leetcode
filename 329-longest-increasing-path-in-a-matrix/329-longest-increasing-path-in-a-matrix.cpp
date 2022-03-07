class Solution {
public:
    int dfs(vector<vector<int>> &matrix,int i,int j,int prev,int dp[201][201]){
        if(i < 0 or j < 0 or i == matrix.size() or j == matrix[0].size()){
            return 0;
        }
        if(matrix[i][j] <= prev){
            return 0;
        }
        if(dp[i][j])
            return dp[i][j];        
        int cur = matrix[i][j];
        int right = dfs(matrix,i,j + 1,cur,dp);
        int bottom = dfs(matrix,i + 1,j,cur,dp);
        int up = dfs(matrix,i - 1,j,cur,dp);
        int left = dfs(matrix,i,j - 1,cur,dp);
        dp[i][j] = max(max(left,right),max(up,bottom)) + 1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int longestPath = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[201][201] = {0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                longestPath = max(longestPath,dfs(matrix,i,j,-1,dp));
            }
        }
        return longestPath;
    }
};
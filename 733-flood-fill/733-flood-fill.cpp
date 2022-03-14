class Solution {
public:
    int newColor;
    int oldColor;
    void dfs(vector<vector<int>> &image,int i,int j){
        if(i < 0 or j < 0 or i == image.size() or j == image[0].size()){
            return;
        }
        if(image[i][j] != oldColor)
            return;
        image[i][j] = newColor;
        dfs(image,i,j + 1);
        dfs(image,i + 1,j);
        dfs(image,i,j - 1);
        dfs(image,i - 1,j);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        this->newColor = newColor;
        this->oldColor = image[sr][sc];
        if(oldColor != newColor)
            dfs(image,sr,sc);
        return image;
    }
};
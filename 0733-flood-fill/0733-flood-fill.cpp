class Solution {
public:
    int color;
    void dfs(vector<vector<int>> &image,int x,int y,int prevColor){
       if(x < 0 or y < 0 or x == image.size() or y == image[0].size()){
           return;
       } 
       if(image[x][y] != prevColor){
           return;
       }
       prevColor = image[x][y];
       image[x][y] = color;
       dfs(image,x,y - 1,prevColor);
       dfs(image,x - 1,y,prevColor);
       dfs(image,x + 1,y,prevColor);
       dfs(image,x,y + 1,prevColor);
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->color = color; 
        if(image[sr][sc] == color)
            return image;
        dfs(image,sr,sc,image[sr][sc]);
        return image;
    }
};
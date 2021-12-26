class Solution {
public:
    int squareDist(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      sort(points.begin(),points.end(),[&](vector<int>& a,vector<int> &b){
          return squareDist(a) < squareDist(b);
      });
      return vector<vector<int>>(points.begin(),points.begin() + k);  
    }
};
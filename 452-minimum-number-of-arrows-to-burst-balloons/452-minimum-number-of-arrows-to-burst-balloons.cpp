class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;
        if(points.size() == 1)
            return count;
        sort(points.begin(),points.end());
        vector<int> prev = points[0];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= prev[1]){
                prev = {points[i][0],min(prev[1],points[i][1])};    
            }
            else {
                count++;
                prev = points[i];
            }
        }
        return count;
    }
};
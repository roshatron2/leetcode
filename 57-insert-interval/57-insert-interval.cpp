class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        while(i < intervals.size() and intervals[i][0] <= newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        if(!res.empty()){
            if(res.back()[1] < newInterval[0]){
                res.push_back(newInterval);
            } else {
                res.back()[1] = max(res.back()[1],newInterval[1]);
            }
        } else {
            res.push_back(newInterval);
        }
        while(i < intervals.size()){
            if(res.back()[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
            i++;
        }
        return res;
    }
};
/*
i - 0
intervals - [[1,5]]
newInterval - [2,3]
res - [[1,5]]
*/
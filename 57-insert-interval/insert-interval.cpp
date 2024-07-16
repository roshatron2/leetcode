class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);    
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for(vector<int>& interval : intervals){
            if(res.empty() or res.back()[1] < interval[0]){
                res.push_back(interval);
            } else {
                res.back() = {res.back()[0], max(res.back()[1], interval[1])};
            }
        }
        return res;
    }
};
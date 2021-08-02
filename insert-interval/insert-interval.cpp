class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(auto interval : intervals){
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1],interval[1]);
            }
        }
        return merged;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
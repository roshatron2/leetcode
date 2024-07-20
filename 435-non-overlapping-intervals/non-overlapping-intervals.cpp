class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int end_val = intervals[0][1];
        int removals = 0;
        for(int i = 1; i < intervals.size(); i++){
                if(intervals[i][0] < end_val){
                    removals++;
                    end_val = min(end_val, intervals[i][1]);
                } else {
                    end_val = intervals[i][1];
                }   
        }
        return removals;
    }
};

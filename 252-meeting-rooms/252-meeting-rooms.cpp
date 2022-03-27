class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return true;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int maxEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < maxEnd)
                return false;
            maxEnd = max(intervals[i][1],maxEnd);
        }
        return true;
    }
};
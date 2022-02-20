class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int covered = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int mx = INT_MIN;
        for(auto interval : intervals){
            if(interval[1] <= mx)
                covered++;
            mx = max(interval[1],mx);
        }
        return intervals.size() - covered;
    }
};
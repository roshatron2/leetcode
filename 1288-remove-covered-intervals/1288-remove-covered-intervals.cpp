class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int covered = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int farthest_endpoint = INT_MIN;
        for(auto &interval : intervals){
            if(interval[1] <= farthest_endpoint)
                covered++;
            farthest_endpoint = max(interval[1],farthest_endpoint);
        }
        return intervals.size() - covered;
    }
};
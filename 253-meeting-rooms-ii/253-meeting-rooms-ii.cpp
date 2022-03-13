class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            return a[0] < b[0];
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0][1]);
        intervals = vector<vector<int>>(intervals.begin() + 1,intervals.end());
        for(auto interval : intervals){
            if(pq.top() <= interval[0]){
                pq.pop();
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start, end;    

        for(vector<int> interval : intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int l = 0, r = 0;
        int res = 0;
        int groups = 0;

        while(l < intervals.size()){
            if(start[l] <= end[r]){
                l++;
                groups += 1;
            } else {
                r++;
                groups -= 1;
            }
            res = max(res, groups);
        }
        return res;
    }
};
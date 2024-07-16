class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());    
        vector<vector<int>> res; 

        for(vector<int>& interval : intervals){
            if(res.empty() or res.back()[1] < interval[0]){
                res.push_back(interval);
            } else {
                res.back() = {res.back()[0], max(interval[1], res.back()[1])};
            }           
        }
        return res;
    }
};
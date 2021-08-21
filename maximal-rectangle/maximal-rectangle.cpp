class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> p,h;
        h.push(0);
        p.push(-1);
        int mx = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] > h.top()){
                h.push(heights[i]);
                p.push(i);
            } else {
                int last = INT_MAX;
                while(heights[i] < h.top()){
                    last = p.top();
                    int cur = (i - p.top()) * h.top();
                    mx = max(cur,mx);
                    h.pop();p.pop();
                }
                h.push(heights[i]);
                p.push(min(i,last));
            }
        }
        while(!h.empty()){
            int cur = (heights.size() - p.top()) * h.top();
            h.pop();p.pop();
            mx = max(mx,cur);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        if(matrix.empty())
            return 0;
        vector<int> heights(matrix[0].size(),0);
        for(int i = 0;  i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            int cur = largestRectangleArea(heights);
            mx = max(mx,cur);
        }
        return mx;
    }
};
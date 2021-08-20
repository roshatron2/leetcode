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
};
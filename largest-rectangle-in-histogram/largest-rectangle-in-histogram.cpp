class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mx = 0;
        int n = heights.size();
        stack<int> p,h;
        h.push(0);
        p.push(-1);
     
        for(int i = 0; i < n; i++){
            if(h.top() < heights[i]){
                h.push(heights[i]);
                p.push(i);
            } else {
                int last = INT_MAX;
                while(heights[i] < h.top()){
                    last = p.top();
                    int cur = ((i - p.top()) * h.top());
                    h.pop(); p.pop();
                    mx = max(cur,mx);
                }
                h.push(heights[i]);
                p.push(min(last,i));
            }
        }
        while(!h.empty()){
            int cur = (heights.size() - p.top()) * h.top();
            h.pop();
            p.pop();
            mx = max(mx,cur);
        }
        return mx;
    }
};
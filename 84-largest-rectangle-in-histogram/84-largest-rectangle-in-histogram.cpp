class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mx = 0;
        stack<int> h,p;
        
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!h.empty() and h.top() > heights[i]){
                start = p.top();
                mx = max(mx,h.top() * (i - p.top()));
                h.pop();
                p.pop();
            }
            h.push(heights[i]);
            p.push(start);
        }
        while(!h.empty()){
            int cur = h.top() * (heights.size() - p.top());
            mx = max(mx,cur);
            h.pop();
            p.pop();
        }
        return mx;
    }
};
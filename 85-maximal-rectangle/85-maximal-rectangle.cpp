class Solution {
public:
    int largestHistogram(vector<int> nums){
        int mx = 0;
        stack<int> h,p;
        for(int i = 0; i < nums.size(); i++){
            int start = i;
            while(!h.empty() and nums[i] < h.top()){
                int cur = h.top() * (i - p.top());
                mx = max(cur,mx);
                start = p.top();
                h.pop();
                p.pop();
            }
            h.push(nums[i]);
            p.push(start);
        }
        while(!h.empty()){
            int cur = h.top() * (nums.size() - p.top());
            mx = max(mx,cur);
            h.pop();
            p.pop();
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> nums(matrix[0].size(),0);
        int mx = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    nums[j]++;
                } else {
                    nums[j] = 0;
                }
            }
            mx = max(largestHistogram(nums),mx);
        }
        return mx;
    }
};
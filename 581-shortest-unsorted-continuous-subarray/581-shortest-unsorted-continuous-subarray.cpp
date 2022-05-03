class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stack;
        int l = nums.size(),r = 0;
        for(int i = 0; i < nums.size(); i++){
            while(!stack.empty() and nums[stack.top()] > nums[i]){
                l = min(l,stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty())
            stack.pop();
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!stack.empty() and nums[stack.top()] < nums[i]){
                r = max(r,stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        int len = r - l + 1;
        return len > 0 ? len : 0;
    }
};
/*
0 1 2 3  4 5 6
2 6 4 8 10 9 15
stack - 0 1 
*/
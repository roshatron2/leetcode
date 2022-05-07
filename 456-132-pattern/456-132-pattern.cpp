class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        
        stack<int> stack;
        vector<int> minArray(n);
        minArray[0] = nums[0];
        for(int i = 1; i < n; i++){
            minArray[i] = min(minArray[i - 1],nums[i]);
        }
        for(int j = n - 1; j >= 0; j--){
            if(nums[j] <= minArray[j]){
                continue;
            }
            while(!stack.empty() and stack.top() <= minArray[j]){
                stack.pop();
            }
            if(!stack.empty() and stack.top() < nums[j]){
                return true;
            }
            stack.push(nums[j]);
        }
        return false;
    }
};
/*
1 3 2
1 1 1
s - 2
*/

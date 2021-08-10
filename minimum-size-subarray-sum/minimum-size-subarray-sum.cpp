class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0,j = 0,len = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                sum -= nums[j];
                len = min(len,i + 1 - j);
                j++;
            }
        }
        return len != INT_MAX ? len : 0;
    }
};
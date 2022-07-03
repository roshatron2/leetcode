class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int prevDiff = nums[1] - nums[0];
        int len = prevDiff != 0 ? 2 : 1;
        for(int i = 2; i < nums.size(); i++){
            int diff = nums[i] - nums[i - 1];
            if(prevDiff <= 0 and diff > 0 or prevDiff >= 0 and diff < 0){
                len++;
                prevDiff = diff;
            }
        }
        return len;
    }
};
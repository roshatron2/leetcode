class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i-1] < nums[i] and nums[i] > nums[i+1]){
                return i;
            }
        }
        return 0;  
    }
};
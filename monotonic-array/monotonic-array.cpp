class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int inc = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] <= nums[i + 1])
                inc++;
        }
        int dec = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] >= nums[i + 1])
                dec++;
        }
        if(dec == n - 1 or inc == n - 1)
            return true;
        else
            return false;
        
    }
};
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modified = false; 
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                if(modified)
                    return false;
                if(i - 1 < 0 or nums[i + 1] - nums[i - 1] >= 0)
                    modified = true;
                else if(i + 2 >= n or nums[i + 2] - nums[i] >= 0)
                    modified = true;
                else
                    return false;
            }
        }
        return true;
    }
};
/*
find an i such that a[i] > a[i + 1]
replace a[i] with a number x such that x >= a[i - 1] and x <= a[i + 1]
or replace a[i + 1] with a number x such that x >= a[i] and x < a[i + 2]
*/

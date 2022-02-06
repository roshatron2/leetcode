class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        bool present = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(!present){
                    nums[j++] = nums[i];
                    present = true;
                }
            } else {
                nums[j++] = nums[i];
                present = false;
            }
        }
        return j;
    }
};
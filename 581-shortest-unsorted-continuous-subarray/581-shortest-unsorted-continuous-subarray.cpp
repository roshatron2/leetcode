class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        int i = 0,j = nums.size() - 1;
        
        while(i < nums.size()){
            if(nums[i] != copy[i])
                break;
            i++;
        }
        while(j >= 0){
            if(nums[j] != copy[j])
                break;
            j--;
        }
        int len = j - i + 1;
        return len > 0 ? len : 0;
    }
};
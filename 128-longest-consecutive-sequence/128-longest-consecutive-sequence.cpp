class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int mx = 1,count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] == 1){
                count++;
            } else if(nums[i] == nums[i - 1]){
                continue; 
            }
            else {
               mx = max(mx,count);
               count = 1;
            }  
        }
        return max(mx,count);
    }
};

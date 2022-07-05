class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());    
        int curSeq = 1,maxSeq = 1;
        for(int i = 1; i < nums.size(); i++){
           if(nums[i] == nums[i - 1])
               continue;
           if(nums[i] == nums[i - 1] + 1){
               curSeq++;
           } else {
               curSeq = 1;
           } 
           maxSeq = max(maxSeq,curSeq);
        }
        return maxSeq;
    }
};
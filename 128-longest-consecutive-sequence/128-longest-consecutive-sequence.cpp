class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());    
        int curStreak = 0,maxStreak = 0;
        for(int i : nums){
            if(set.find(i - 1) == set.end()){
               curStreak = 1; 
               int cur = i;
               while(set.find(cur + 1) != set.end()){
                   cur++;
                   curStreak++;
               }
               maxStreak = max(curStreak,maxStreak);
            }
        }
        return maxStreak;
    }
};
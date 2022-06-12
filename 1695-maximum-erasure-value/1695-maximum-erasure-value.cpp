class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int l = 0,r = 0,ans = 0,sum = 0;
        bool hasDuplicate = false;
        while(r < nums.size()){
           sum += nums[r];
           if(++map[nums[r++]] > 1){
               hasDuplicate = true;
           }
           while(hasDuplicate){
              sum -= nums[l];   
              if(--map[nums[l++]] == 1){
                  hasDuplicate = false;
              }
           }
           ans = max(ans,sum); 
        }
        return ans;
    }
};
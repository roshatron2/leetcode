class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int l = 0,r = 0,ans = 0,sum = 0,counter = 0;
        while(r < nums.size()){
           sum += nums[r];
           map[nums[r]]++;
           if(map[nums[r]] > 1){
               counter++;
           }
           while(counter){
              sum -= nums[l];   
              map[nums[l]]--;
              if(map[nums[l]] == 1){
                 counter--;   
              }
              l++;
           }
           ans = max(ans,sum); 
           r++;
        }
        return ans;
    }
};
/*
0 1 2 3 4
4 2 4 5 6
l - 1
r - 4
sum - 17
counter - 0
4: 1
2: 1
5: 1
6: 1


*/
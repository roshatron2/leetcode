class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
           if(map.find(nums[i]) != map.end() and 
              abs(map[nums[i]] - i) <= k){
              return true; 
           } else {
               map[nums[i]] = i;
           } 
        }    
        return false;
    }
};
/*
0 1 2 3
1 2 3 1 | k = 3

i = 3
1: 0
2: 1
3: 3
*/
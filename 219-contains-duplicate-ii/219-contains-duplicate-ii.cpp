class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) != set.end()){
               return true; 
            }
            set.insert(nums[i]);
            if(set.size() > k)
                set.erase(nums[i - k]);
        }
        return false;
    }
};
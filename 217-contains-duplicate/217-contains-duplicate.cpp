class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
        for(int i : nums){
            if(set.find(i) != set.end())
                return true;
            set.insert(i);
        }
        return false;
    }
};
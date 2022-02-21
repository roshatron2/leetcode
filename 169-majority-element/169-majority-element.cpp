class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        for(auto [k,v] : map){
            if(v > nums.size() / 2)
                return k;
        }
        return 0;
    }
};
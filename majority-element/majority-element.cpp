class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(auto i : nums){
            map[i]++;
        }
        for(auto [k,v] : map){
            if(v > n / 2)
                return k;
        }
        return 0;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        for(auto [k,v] : map){
            if(v == 1)
                return k;
        }
        return 0;
    }
};
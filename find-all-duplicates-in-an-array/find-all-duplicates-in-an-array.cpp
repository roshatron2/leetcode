class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> res;
        for(auto i : nums){
            map[i]++;
        }
        for(auto [k,v] : map){
            if(v > 1){
                res.push_back(k);
            }
        }
        return res;
    }
};
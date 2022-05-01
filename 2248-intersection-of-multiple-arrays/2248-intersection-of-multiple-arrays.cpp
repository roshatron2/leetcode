class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> map;
        vector<int> res;
        for(auto row : nums){
            for(int i : row){
                map[i]++;
            }
        }
        for(auto [k,v] : map){
            if(v == nums.size()){
                res.push_back(k);    
            }    
        }
        return res;
    }
};
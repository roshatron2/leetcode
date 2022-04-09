class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        unordered_map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        for(auto [key,value] : map){
            buckets[value].push_back(key);
        }
        vector<int> res;
        for(int i = n; i >= 0 and k > 0; i--){
            if(!buckets[i].empty()){
                for(int ele : buckets[i]){
                    res.push_back(ele);
                    k--;
                }
            }
        }
        return res;
    }
};
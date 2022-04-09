class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int i : nums){
            map[i]++;
        }
        auto cmp = [](pair<int,int> a,pair<int,int> b){
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(auto [key,value] : map){
            pq.push({key,value});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
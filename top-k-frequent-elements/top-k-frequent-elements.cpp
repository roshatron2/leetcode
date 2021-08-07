class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i : map){
            pq.push(make_pair(i.second,i.first));
        }
        vector<int> res;
        while(!pq.empty() and k > 0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
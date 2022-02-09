struct cmp {
        bool operator()(pair<int,int> a,pair<int,int> b){
                    return a.second  < b.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int i : nums){
            map[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto [key,value] : map){
            pq.push(make_pair(key,value));
        }
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return vector<int>(res.begin(),res.begin() + k);
    }
};
//1 : 3
//2 : 2
//3 : 1
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto cmp = [](pair<int,int> a,pair<int,int> b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int i = 0; i < mat.size(); i++){
            int ones = 0;
            for(int j : mat[i]){
                if(j == 1){
                    ones++;
                }
            }
            pair<int,int> cur = make_pair(i,ones);
            pq.push(cur);
        }
        vector<int> res;
        while(!pq.empty() and k){
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};
/*
  1
 2  2
3 5
*/
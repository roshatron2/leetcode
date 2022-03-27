class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        auto cmp = [](pair<int,int> a,pair<int,int> b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int i = 0; i < mat.size(); i++){
            int l = 0,r = n - 1,strength = n,mid;
            
            while(l <= r){
                mid = l + (r - l) / 2;
                if(mat[i][mid]){
                    l = mid + 1;
                } else {
                    strength = min(strength,mid);
                    r = mid - 1;
                }
            }
            pq.push({strength,i});
        }
        vector<int> res;
        while(!pq.empty() and k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> map;
        for(int i = 0; i < mat.size(); i++){
            int l = 0,r = mat[0].size() - 1,pos = r + 1,mid;
            
            while(l <= r){
                mid = l + (r - l) / 2;
                if(mat[i][mid]){
                    l = mid + 1;
                } else {
                    pos = min(pos,mid);
                    r = mid - 1;
                }
            }
            map[pos].push_back(i);
        }
        vector<int> res;
        for(auto i : map){
            for(auto j : map[i.first])
                res.push_back(j);
        }
        return vector<int>(res.begin(),res.begin() + k);
    }
};
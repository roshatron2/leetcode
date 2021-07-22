class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,int> map;
        for(int i = 0; i < edges.size(); i++){
            for(int j = 0; j < edges[i].size(); j++){
                map[edges[i][j]]++;
            }
        }
        for(auto [k,v] : map){
            if(v == n){
                return k;
            }
        }
        return 0;
    }
};
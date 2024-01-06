class Solution {
public:
    int find(int p, vector<int>& parent){
        while(p != parent[p]){
            p = parent[p];
        }
        return p;
    }

    bool merge(int u, int v, vector<int>& rank, vector<int>& parent){
        int pu = find(u, parent);
        int pv = find(v, parent); 

        if(pu == pv){
            return false;
        }
        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
            rank[pu] += rank[pv];
        } else {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        vector<int> rank(n + 1, 1);
        for(vector<int> edge : edges){
            if(!merge(edge[0], edge[1], rank, parent)){
                return {edge[0], edge[1]};
            }
        }
        return {};
    }
};
class Solution {
public:
    int find(vector<int>& parent, int p){
        while(parent[p] != p){
            p = parent[p];
        }
        return p;
    }
    bool merge(vector<int>& parent, vector<int>& rank, int a, int b){
        int parent_a = find(parent, a);
        int parent_b = find(parent, b);
        if(parent_a == parent_b){
            return false;
        }
        if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
            rank[parent_b] += rank[parent_a];
        } else {
            parent[parent_b] = parent_a;
            rank[parent_a] += rank[parent_b];
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1){
            return false;
        }
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(vector<int> edge : edges){
            if(!merge(parent, rank, edge[0], edge[1])){
                return false;
            }
        }
        return true;
    }
};
class UnionFind {
    public:
        vector<int> group;
        vector<int> rank;
        
        UnionFind(int size){
            group = vector<int>(size);
            rank = vector<int>(size);
            for(int i = 0; i < size; i++){
                group[i] = i;
            }
        }
        
        int find(int node){
           if(group[node]  != node){
               group[node] = find(group[node]);
           }
           return group[node];
        }
        bool join(int node1,int node2){
            int group1 = find(node1);
            int group2 = find(node2);
            
            if(group1 == group2){
                return false;
            }
            if(rank[group1] > rank[group2]){
                group[group2] = group1;
            } else if(rank[group1] < rank[group2]){
                group[group1] = group2;
            } else {
                group[group1] = group2;
                rank[group2] += 1;
            }
            return true; 
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       vector<pair<int,pair<int,int>>> allEdges;
       int n = points.size();
       
       for(int i = 0; i < n; i++){
           for(int j = i + 1; j < n; j++){
               int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
               allEdges.push_back({weight,{i,j}});
           }
       }
       sort(allEdges.begin(),allEdges.end());
        
       UnionFind uf(n);
       int edgesUsed = 0;
       int mstCost = 0;
        
       for(int i = 0; i < allEdges.size() and edgesUsed < n - 1; i++){
           int node1 = allEdges[i].second.first;
           int node2 = allEdges[i].second.second;
           int weight = allEdges[i].first; 
           if(uf.join(node1,node2)){
               edgesUsed++;
               mstCost += weight;
           }
       }
       return mstCost;
    }
};
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> map;
        for(auto row : mat){
            for(int i : row){
                map[i]++;
            }
        }
        int minEle = INT_MAX;
        for(auto [k,v] : map){
            if(v == mat.size()){
               minEle = min(minEle,k); 
            }
        }
        return minEle == INT_MAX ? -1 : minEle;
    }
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i : arr){
           map[i]++; 
        }
        unordered_set<int> set;
        for(auto [k,v] : map){
           if(set.find(v) != set.end()){
               return false;
           } 
           set.insert(v);
        }
        return true;
    }
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> set;
        for(auto row : paths){
            for(auto i : row){
                set.insert(i);
            }
        }
        unordered_map<string,int> map;
        for(auto row : paths){
            map[row[0]]++;
        }
        for(auto city : set){
            if(map.find(city) == map.end()){
                return city;
            }
        }
        return "";
    }
};
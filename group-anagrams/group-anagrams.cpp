class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> res;
        for(auto s : strs){
            string t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        for(auto [k,v] : map){
            res.push_back(v);
        }
        return res;
    }
};
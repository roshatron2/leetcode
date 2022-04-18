class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        for(string word : strs){
            string t = word;
            sort(t.begin(),t.end());
            map[t].push_back(word);
        }
        for(auto [k,v] : map){
            res.push_back(v);
        }
        return res;
    }
};
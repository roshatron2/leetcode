class Solution {
public:
    unordered_map<string,bool> map;
    bool isMatch(int i,int j,string s,string p){
        string key = to_string(i) + to_string(j);
        if(map.find(key) != map.end())
            return map[key];
        if(i >= s.size() and j >= p.size())
            return true;
        if(j >= p.size())
            return false;
        bool match = i < s.size() and (s[i] == p[j] or p[j] == '.');
        if(j + 1 < p.size() and p[j+1] == '*'){
            return map[key] = isMatch(i,j+2,s,p) or match and isMatch(i+1,j,s,p);
        }
        if(match){
            return map[key] = isMatch(i+1,j+1,s,p);
        }
        return map[key] = false;
    }
    bool isMatch(string s, string p) {
        return isMatch(0,0,s,p);
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> stmap,tsmap;
        for(int i = 0; i < s.size(); i++){
            if(stmap.find(s[i]) != stmap.end() and stmap[s[i]] != t[i]){
                return false;
            }
            if(tsmap.find(t[i]) != tsmap.end() and tsmap[t[i]] != s[i]){
                return false;
            }
            stmap[s[i]] = t[i];
            tsmap[t[i]] = s[i];
        }
        return true; 
    }
};
/*
tmap
b: b
a: a
smap
b: b
a: a
d: b


*/
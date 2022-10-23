class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> st_map,ts_map;
       for(int i = 0; i < s.size(); i++){
           if(st_map.count(s[i]) != 0 and st_map[s[i]] != t[i]){
               return false;
           }
           if(ts_map.count(t[i]) != 0 and ts_map[t[i]] != s[i]){
               return false;
           }
           st_map[s[i]] = t[i];
           ts_map[t[i]] = s[i];
       } 
       return true;
    }
};
/*
egg -> add
e : a | a : g
g : d | d : g


foo -> bar
f : b
o : a
o already in the map and doesn't map to the same character

paper -> title
p : t
a : i
e : l
r : e

badc -> baba
b : b
a : a
d : b
c : a

need to keep track of mappings in both directions, or else will fail for certain test cases
*/
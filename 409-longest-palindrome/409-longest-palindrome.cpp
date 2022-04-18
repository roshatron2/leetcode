class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(char i : s){
           map[i]++; 
        }
        int res = 0;
        for(auto [k,v] : map){
            if(v % 2 == 0){
               res += v; 
            } else {
                res += v - 1;
            }
        }
        return res < s.size() ? res + 1 : res;
    }
};
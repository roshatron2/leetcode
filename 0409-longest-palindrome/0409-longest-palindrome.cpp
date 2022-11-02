class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int res = 0;
        for(char i : s){
            map[i]++;
        }
        for( auto [k,v] : map ){
            if(v % 2 == 0){
                res += v;
            } else if(v % 2 == 1) {
               res += v - 1; 
            }     
        }
        return res % 2 == 0 and res < s.size() ? res + 1 : res;
    }
};
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> map;
        for(char i : s){
           map[i]++; 
        }
        int count = 0;
        for(auto [k,v] : map){
           count += v % 2; 
        }
        return count <= 1;
    }
};
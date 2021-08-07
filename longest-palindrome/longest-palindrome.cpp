class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int ans = 0;
        for(char i : s){
            map[i]++;
        }
        for(auto [k,v] : map){
            ans += v / 2 * 2;
        }
        if(ans < s.size())
            ans++;
        return ans;
        
        
    }
};
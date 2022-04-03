class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int l = 0,r = 0,ans = INT_MIN;
        while(r < s.size()){
            if(map.find(s[r]) != map.end()){
                ans = max(ans,r - l);
                l = max(l,map[s[r]] + 1);
            }
            map[s[r]] = r;
            r++;
        }
        return max(ans,r - l);
    }
};
/*
01
au
l 0
r 0
a:
u:
*/
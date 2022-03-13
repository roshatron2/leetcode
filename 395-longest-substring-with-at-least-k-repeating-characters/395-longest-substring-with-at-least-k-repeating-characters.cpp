class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty())   
            return 0;
        unordered_map<char,int> map;
        for(char i : s){
            map[i]++;
        }
        int pos = 0;
        while(pos < s.size() and map[s[pos]] >= k){
            pos++;
        }
        if(pos == s.size())
            return s.size();
        int left = longestSubstring(s.substr(0,pos),k);
        int right = longestSubstring(s.substr(pos + 1),k);
        return max(left,right);
    }
};
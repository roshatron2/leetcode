class Solution {
public:
    string minWindow(string s, string t) {
        if(t == s)
            return s;
        int l = 0,r = 0,start = 0,min = INT_MAX;
        unordered_map<char,int> map;
        for(char i : t){
            map[i]++;
        }
        int required = t.size();
        while(r <= s.size() and l < s.size()){
            if(required){
                map[s[r]]--;
                if(map[s[r]] >= 0)
                    required--;
                r++;
            } else {
                if(r - l < min){
                    min = r - l;
                    start = l;
                }
                map[s[l]]++;
                if(map[s[l]] > 0)
                    required++;
                l++;
            }
        }
        return min == INT_MAX ? "" : s.substr(start,min);
    }
};
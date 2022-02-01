class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0,r = 0,start = 0,len = INT_MAX,rem = t.size();
        unordered_map<char,int> map;
        for(char i : t){
            map[i]++;
        }
        while(r < s.size()){
            map[s[r]]--;
            if(map[s[r]] >= 0)
                rem--;
            r++;
            while(rem == 0){
                if(len > r - l){
                    start = l;
                    len = r - l;
                }
                map[s[l]]++;
                if(map[s[l]] == 1)
                    rem++;
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
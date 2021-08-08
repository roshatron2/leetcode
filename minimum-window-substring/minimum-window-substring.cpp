class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0,r = 0,start = 0,len = INT_MAX;
        unordered_map<char,int> map;
        for(auto i : t){
            map[i]++;
        }
        int counter = t.size();
        
        while(r < s.size()){
            if(counter){
                map[s[r]]--;
                if(map[s[r]] >= 0){
                    counter--;
                }
                r++;
            }
            while(counter == 0){
                if(r - l < len){
                    start = l;
                    len = r - l;
                }
                map[s[l]]++;
                if(map[s[l]] > 0){
                    counter++;
                }
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
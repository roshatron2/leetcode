class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> map;
        vector<int> res;
        for(char i : p){
            map[i]++;
        }
        int l = 0,r = 0,start,rem = p.size(),len = INT_MAX;
        while(r < s.size()){
            map[s[r]]--;
            if(map[s[r]] >= 0)
                rem--;
            r++;
            while(rem == 0){
                len = r - l;
                if(len == p.size())
                    res.push_back(l);
                map[s[l]]++;
                if(map[s[l]] == 1)
                    rem++;
                l++;
            }
        }
        return res;
    }
};
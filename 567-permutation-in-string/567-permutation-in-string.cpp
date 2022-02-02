class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0,r = 0,rem = s1.size();
        unordered_map<char,int> map;
        for(char i : s1){
            map[i]++;
        }
        while(r < s2.size()){
            map[s2[r]]--;
            if(map[s2[r]] >= 0){
                rem--;
            }
            r++;
            while(rem == 0){
                if(r - l == s1.size())
                    return true;
                map[s2[l]]++;
                if(map[s2[l]] == 1)
                    rem++;
                l++;
            }
        }
        return false;
    }
};
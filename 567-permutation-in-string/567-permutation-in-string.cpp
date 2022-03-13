class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> map;
        for(auto i : s1){
            map[i]++;
        }
        int l = 0,r = 0,counter = s1.size();
        while(r < s2.size()){
            map[s2[r]]--;
            if(map[s2[r]] >= 0){
                counter--;
            }
            r++;
            while(counter == 0){
                if(r - l == s1.size())
                    return true;
                map[s2[l]]++;
                if(map[s2[l]] == 1){
                    counter++;
                }
                l++;
            }
        }
        return false;
    }
};

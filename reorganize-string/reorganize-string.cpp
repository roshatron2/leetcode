class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        for(auto i : s){
            map[i]++;
        }
        char mostFreq = s[0];
        for(auto i : map){
            if(i.second > map[mostFreq]){
                mostFreq = i.first;
            }
        }
        if(map[mostFreq] * 2 - 1 > s.size()){
            return "";
        }
        int i = 0;
        while(map[mostFreq]){
            s[i] = mostFreq;
            i += 2;
            map[mostFreq]--;
        }
        for(char c = 'a'; c <= 'z'; c++){
            while(map[c]){
                if(i >= s.size()){
                    i = 1;
                }
                s[i] = c;
                map[c]--;
                i += 2;
            }
        }
        return s;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char i : s){
            map[i]++;
        }
        sort(s.begin(),s.end(),[&map](char a,char b){
            if(map[a] == map[b])
                return a < b;
            return map[a] > map[b];
        });
        return s;
    }
};
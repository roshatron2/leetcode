class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> map;
        for(char i : s){
            map[i]++;
        }
        vector<int> freqs;
        for(auto [letter,freq] : map){
            freqs.push_back(freq);
        }
        sort(freqs.begin(),freqs.end(),greater<int>());
        int maxAllowedFreq = s.size();
        int deletions = 0;
        for(int &freq : freqs){
            if(freq > maxAllowedFreq){
                deletions += freq - maxAllowedFreq; 
                freq = maxAllowedFreq;
            }
            maxAllowedFreq = max(0,freq - 1);
        }
        return deletions;
    }
};
/*
aaabbbcc
a:3
b:3
c:2

bbcebab
b:4 c:1 e:0 a:1
-1
*/
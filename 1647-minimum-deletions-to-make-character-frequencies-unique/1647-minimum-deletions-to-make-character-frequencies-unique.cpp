class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> seen;
        unordered_map<char,int> map;
        int deletions = 0;
        for(char i : s){
           map[i]++; 
        } 
        for(auto [letter,freq] : map){
            if(seen.find(freq) == seen.end()){
                seen.insert(freq);
            } else {
                while(seen.find(freq) != seen.end() and freq != 0){
                    freq--;
                    deletions++;
                }
                seen.insert(freq);
            }
        }
        return deletions;
    }
};

/*
aaabbbcc
a: 3
b: 3
c: 2
seen: [3,2,1]
del - 2
TC - O(unique letters in string * highest Frequency)
*/
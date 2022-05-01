class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> map1,map2;
        int count = 0;
        for(string word : words1){
            map1[word] += 1;
        }
        for(string word : words2){
            map2[word] += 1;
        }
        for(string word : words1){
            if(map1[word] == 1 and map2[word] == 1){
               count++; 
            }
        }
        return count;
    }
};
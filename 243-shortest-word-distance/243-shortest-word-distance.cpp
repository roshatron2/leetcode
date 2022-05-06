class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string,vector<int>> map;
        for(int i = 0; i < wordsDict.size(); i++){
           if(map.find(wordsDict[i]) == map.end()){
              map[wordsDict[i]] = {i};
           }
           else {
              map[wordsDict[i]].push_back(i); 
           }
        }
        int dist = INT_MAX;
        for(int i : map[word1]){
            for(int j : map[word2]){
               dist = min(dist,abs(i - j)); 
            }
        }
        return dist;
    }
};
/*
practice : [0]
makes : [1,4]
perfect: [2]
coding: [3]
*/
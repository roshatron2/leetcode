class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int minDist = INT_MAX;
        int l = -1,r = -1;
        for(int i = 0; i < wordsDict.size(); i++){
           if(wordsDict[i] == word1){
               l = i;
           }
           if(wordsDict[i] == word2){
               r = i;
           }
           if(l != -1 and r != -1)
               minDist = min(minDist,abs(l - r));
        }
        return minDist;
    }
};
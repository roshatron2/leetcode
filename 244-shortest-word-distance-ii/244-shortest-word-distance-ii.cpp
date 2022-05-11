class WordDistance {
public:
    vector<string> words;
    unordered_map<string,vector<int>> map;
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++){
            map[wordsDict[i]].push_back(i);
        }    
    }
    
    int shortest(string word1, string word2) {
        vector<int> w1 = map[word1];
        vector<int> w2 = map[word2];
        int i = 0,j = 0;
        int minDist = INT_MAX;
        while(i < w1.size() and j < w2.size()){
            minDist = min(minDist,abs(w1[i] - w2[j]));
            if(w1[i] < w2[j]){
                i++;
            } else {
                j++;
            }
        }
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
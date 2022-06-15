class Solution {
public:
    unordered_map<string,int> map;
    int dfs(string word,unordered_set<string> wordsPresent){
       if(word.empty()){
           return 0;
       } 
       if(map[word])
           return map[word];
       int maxLen = 1;
       for(int i = 0; i < word.size(); i++){
           string newWord;
           for(int j = 0; j < word.size(); j++){
               if(j != i){
                  newWord += word[j]; 
               }
           }
           if(wordsPresent.find(newWord) != wordsPresent.end()){
               maxLen = max(maxLen,dfs(newWord,wordsPresent) + 1);
           }
       }
       return map[word] = maxLen;
    }
    int longestStrChain(vector<string>& words) {
        int longestChain = 1;
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),[](string word1,string word2){
           return word1.size() < word2.size(); 
        });
        
        for(string word : words){
            dp[word] = 1; 
            for(int i = 0; i < word.size(); i++){
                string predecessor = word.substr(0,i) + word.substr(i + 1);
                    dp[word] = max(dp[word],dp[predecessor] + 1);
            }
            longestChain = max(dp[word],longestChain);
        }
        return longestChain;
    }
};
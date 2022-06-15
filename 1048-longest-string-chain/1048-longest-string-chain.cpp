class Solution {
public:
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
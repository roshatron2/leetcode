class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    return ladder;
                }
                for(int i = 0; i < word.size(); i++){
                    string backup = word;
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch;
                        if(wordSet.find(word) != wordSet.end()){
                            wordSet.erase(word);
                            q.push(word);
                        }
                    }
                    word = backup;
                }
            }
            ladder++;
        }
        return 0;
    }
};
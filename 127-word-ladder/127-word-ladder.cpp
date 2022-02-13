class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                set.erase(word);
                if (word == endWord) {
                    return ans;
                }
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (set.find(word) != set.end()) {
                            q.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ans++;
        }
        return 0;
    }
};
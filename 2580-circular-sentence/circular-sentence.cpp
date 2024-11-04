class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);        
        string word;
        vector<string> words;
        while(getline(ss, word, ' ')) {
            words.push_back(word);
        }

        for(int i = 0; i < words.size() - 1; i++){
            if(words[i].back() != words[i + 1][0]) {
                return false; 
            }
        }

        return sentence.back() != sentence[0] ? false : true;
    }
};
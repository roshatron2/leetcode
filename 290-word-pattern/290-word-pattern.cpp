class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) return false;
        unordered_map<string, char> map;
        set<char> set;

        for (int i = 0; i < pattern.size(); i++) {
            if (map.find(words[i]) == map.end() and set.find(pattern[i]) == set.end()) {
                set.insert(pattern[i]);
                map.emplace(words[i], pattern[i]);
            } else {
                if (map[words[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
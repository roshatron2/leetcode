class TrieNode {
   public:
    TrieNode *child[26];
    bool isLeaf = false;
    TrieNode *get(char ch) {
        return child[ch - 'a'];
    }
    void put(char ch, TrieNode *node) {
        child[ch - 'a'] = node;
    }
    bool containsKey(char ch) {
        return child[ch - 'a'] != NULL;
    }
    void setEnd() {
        isLeaf = true;
    }
    bool isEnd() {
        return isLeaf;
    }
};

class Trie {
   public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode *node = root;
        for (char i : word) {
            if (!node->containsKey(i)) {
                node->put(i, new TrieNode());
            }
            node = node->get(i);
        }
        node->setEnd();
    }

    void dfs(TrieNode *cur, vector<string> &res, string word) {
        if (res.size() == 3){
            return;
        }
        if (cur->isEnd()) {
            res.push_back(word);
        }
        for (char i = 'a'; i <= 'z'; i++) {
            if (cur->containsKey(i)) {
                dfs(cur->get(i), res, word + i);
            }
        }
    }

    vector<string> getWords(string prefix) {
        TrieNode *cur = root;
        vector<string> res;
        for (char i : prefix) {
            if (!cur->containsKey(i)) {
                return res;
            }
            cur = cur->get(i);
        }
        dfs(cur, res, prefix);
        return res;
    }
};

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        Trie t;
        for (string product : products) {
            t.insert(product);
        }
        string prefix;
        vector<vector<string>> res;
        for (char i : searchWord) {
            prefix += i;
            res.push_back(t.getWords(prefix));
        }
        return res;
    }
};
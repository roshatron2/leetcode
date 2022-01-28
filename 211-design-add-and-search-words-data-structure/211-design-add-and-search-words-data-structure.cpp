class TrieNode {
   public:
    TrieNode *child[26];
    bool isLeaf = false;

    void put(char ch, TrieNode* node) {
        child[ch - 'a'] = node;
    }
    TrieNode* get(char ch) {
        return child[ch - 'a'];
    }
};
class WordDictionary {
   public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *node = root;
        for (char i : word) {
            if (!node->get(i)) {
                node->put(i, new TrieNode());
            }
            node = node->get(i);
        }
        node->isLeaf = true;;
    }
    bool search(string word,TrieNode *root,int k){
        TrieNode *node = root;
        if(word.size() == k)
            return node->isLeaf;
        if(word[k] != '.'){
            TrieNode *cur = node->get(word[k]);
            return cur and search(word,cur,k + 1);
        } else {
            for(int j = 0; j < 26; j++){
                if(node->child[j] and search(word,node->child[j],k + 1))
                    return true;
            }
        }
        return false;
    }
    bool search(string word) {
        return search(word,root,0);
    }
};
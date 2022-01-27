class TrieNode {
    TrieNode *child[26];
    bool isLeaf = false;
    public:
    void put(char ch, TrieNode *node){
        child[ch - 'a'] = node;
    }
    TrieNode* get(char ch){
        return child[ch - 'a'];
    }
    bool containsKey(char ch){
        return child[ch - 'a'] != NULL;
    }
    void setEnd(){
        isLeaf = true;
    }
    bool isEnd(){
       return isLeaf; 
    }
};
class Trie {
public:
    TrieNode *root = new TrieNode();
    Trie() {
      root = new TrieNode();  
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
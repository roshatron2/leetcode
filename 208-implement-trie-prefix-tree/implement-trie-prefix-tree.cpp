class Trie {
    class TrieNode {
        public:
            TrieNode* nodes[26];
            bool isLeaf;
            TrieNode(){
                isLeaf = false;
                for(int i = 0; i < 26; i++) {
                    nodes[i] = nullptr;
                }
            }
            TrieNode* get(char i){
                return nodes[i -'a'];
            }
            void put(TrieNode* node, char i){
                nodes[i -'a'] = node;
            }
            bool contains(char i){
                return nodes[i -'a'] != nullptr;
            }
    };
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char i :  word){
            if(!cur->contains(i)){
                cur->put(new TrieNode(), i);
            } 
            cur = cur->get(i);
        }
        cur->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char i : word){
            if(!cur->contains(i)){
                return false;
            } 
            cur = cur->get(i);
        }    
        return cur->isLeaf;
    }
    
    bool startsWith(string prefix) {
       TrieNode* cur = root; 
       for(char i : prefix){
           if(!cur->contains(i)){
               return false;
           } 
           cur = cur->get(i);
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
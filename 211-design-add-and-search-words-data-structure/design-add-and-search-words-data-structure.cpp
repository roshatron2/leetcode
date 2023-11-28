class TrieNode {
    public:
        TrieNode* children[26] = {nullptr};
        bool isLeaf;
        TrieNode(){
           isLeaf = false; 
        }
        TrieNode* get(char ch){
            return children[ch - 'a'];
        }
        void put(TrieNode* node, char ch){
            children[ch -'a'] = node;
        }
        bool contains(char ch){
            return children[ch - 'a'] != nullptr; 
        }
};
class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
       TrieNode* cur = root; 
       for(char i : word){
          if(!cur->contains(i)){
              cur->put(new TrieNode(), i);
          }
          cur = cur->get(i);
       }
       cur->isLeaf = true;
    }
    bool searchHelper(TrieNode* root, string word){
        TrieNode* cur = root;    
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(cur->contains(ch) and searchHelper(cur->get(ch), word.substr(i + 1))){
                        return true;
                    } 
                }
                return false;
            }
            if(!cur->contains(word[i])){
                return false;
            }
            cur = cur->get(word[i]);
        }
        return cur->isLeaf;
    } 
    bool search(string word) {
        return searchHelper(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
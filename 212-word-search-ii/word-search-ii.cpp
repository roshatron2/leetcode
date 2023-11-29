class Solution {
    class TrieNode {
    public:
        TrieNode* children[26] = {nullptr};
        bool isLeaf;
        string word;

        TrieNode(string word){
            isLeaf = false;
            this->word = word;
        }

        TrieNode* get(char ch){
            return children[ch - 'a'];
        }
        void put(TrieNode* node, char ch){
            children[ch -'a'] = node;
        }
        bool contains(char ch){
            return children[ch -'a'] != nullptr;
        }
    };
    class Trie {
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode("");
        }
        void insert(string word){
            TrieNode* cur = root;
            string s;
            for(char i : word){
                s += i;
                if(!cur->contains(i)){
                    cur->put(new TrieNode(s), i);
                }
                cur = cur->get(i);
            }
            cur->isLeaf = true;
        }
    } t;
public:
    vector<string> res;
    void dfs(vector<vector<char>>& board, int i, int j, string word, TrieNode*  p){
        if(i == -1 or j == -1 or i == board.size() or j == board[0].size()){
            return;
        }       
        char temp = board[i][j];
        if(board[i][j] == '.' or !p->contains(temp)){
            return;
        }
        p = p->get(temp);
        if(p->isLeaf){
            res.push_back(p->word);
            p->isLeaf = false;
        }

        board[i][j] = '.';
        word += temp;
        dfs(board, i + 1, j, word, p);
        dfs(board, i, j + 1, word, p);
        dfs(board, i - 1, j, word, p);
        dfs(board, i, j - 1, word, p);
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word : words){
            t.insert(word);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j,"", t.root);
            }
        }
        return res;
    }
};
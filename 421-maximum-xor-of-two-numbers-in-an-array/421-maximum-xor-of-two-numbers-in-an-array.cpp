class TrieNode {
    TrieNode *child[2];
    bool isLeaf;
    public:
        void put(int bit,TrieNode *node){
            child[bit] = node;
        }
        TrieNode* get(int bit){
            return child[bit];
        }
        bool containsKey(int bit){
            return child[bit] != NULL;
        }
        void setEnd(){
            isLeaf = true;
        }
        bool isEnd(){
            return isLeaf;
        }
};

class Trie {
    TrieNode *root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(int num){
            TrieNode* node = root;
            for(int i = 31; i >= 0; i--){
                int bit = num >> i & 1;
                if(!node->containsKey(bit)) 
                    node->put(bit,new TrieNode());
                node = node->get(bit);
            }
        }
        int getMax(int num){
            TrieNode* node = root;
            int mx = 0;
            for(int i = 31; i >= 0; i--){
                int bit = num >> i & 1;
                if(node->containsKey(1 - bit)){
                    node = node->get(1 - bit);
                    mx |= 1 << i;
                } else {
                    node = node->get(bit);
                }
            }
            return mx;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        
        for(int &i : nums){
            t.insert(i);
        }
        int mx = 0;
        for(int &i : nums){
            mx = max(t.getMax(i),mx);
        }
        return mx;
    }
};
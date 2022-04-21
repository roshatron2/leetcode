class MyHashSet {
public:
    int prime;
    vector<list<int>> table;
    
    int hash(int key){
       return key % prime; 
    }
    auto search(int key){
       int bucket = hash(key);
       return find(table[bucket].begin(),table[bucket].end(),key);
    }
    MyHashSet(): prime(10007), table(prime) {
        
    }
    
    void add(int key) {
       int h = hash(key);
       if(search(key) == table[h].end())
           table[h].push_back(key);
    }
    
    void remove(int key) {
       int h = hash(key);
       auto it = search(key);
       if(it != table[h].end())
           table[h].erase(it);
    }
    
    bool contains(int key) {
        int h = hash(key);
        return search(key) != table[h].end(); 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
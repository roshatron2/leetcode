class MyHashMap {
public:
    vector<vector<pair<int,int>>> map;
    int prime;
    MyHashMap() {
        prime = 10007;
        map.resize(prime);
    }
    
    void put(int key, int value) {
        int hash = key % prime;
        for(auto &pair : map[hash]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        map[hash].push_back({key,value});
    }
    
    int get(int key) {
        int hash = key % prime;
        for(auto pair : map[hash]){
            if(pair.first == key)
                return pair.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = key % prime;
        auto it = map[hash].begin();
        for(;it != map[hash].end(); it++){
            if(it->first == key)
                break;
        }
        if(it != map[hash].end())
            map[hash].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
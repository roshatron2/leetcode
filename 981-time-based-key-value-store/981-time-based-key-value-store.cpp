class TimeMap {
public:
    unordered_map<string,map<int,string>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       map[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        if(map[key].find(timestamp) != map[key].end()){
            return map[key][timestamp];    
        } 
        auto it = map[key].upper_bound(timestamp);
        if(it == map[key].begin()){
            return "";
        }
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
/*
*/
/*

1 3 5 9 10

foo -> 
       4 : bar2
       1 : bar
get(5)       
mid = 3
0 1
1 4

*/
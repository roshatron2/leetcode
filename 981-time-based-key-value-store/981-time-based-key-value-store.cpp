class TimeMap {
public:
    unordered_map<string,map<int,string,greater<int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       map[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        if(map[key].find(timestamp) != map[key].end()){
            return map[key][timestamp];    
        } 
        for(auto [t,v] : map[key]){
           if(t < timestamp){
               return v;
           } 
        }
        return "";
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
if timestamp exists return the value for that timestamp
else return the value which belongs to the lartest t' such that t' < t

timestamps are sorted in descending order 

since the timestamps are sorted in descending order we can use binary serach to find the t' such that t' is less than t in O(logn) time

foo -> 
       4 : bar2
       1 : bar
*/
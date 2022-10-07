class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
       int lo = 0,hi = map[key].size() - 1,ans; 
       while(lo <= hi){
           int mid = lo + (hi - lo) / 2;
           if(map[key][mid].first <= timestamp ){
               lo = mid + 1;
               ans = mid;
           } else if(map[key][mid].first > timestamp){
               hi = mid - 1;
           } 
       }
       if(hi == - 1)
           return "";
       return map[key][ans].second;
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
find largest number less than or equal to 4
0 1 2 3 4 
1 3 5 9 10
lo = 1
hi = 1
mid = 1

*/
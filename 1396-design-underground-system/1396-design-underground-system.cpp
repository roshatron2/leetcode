class UndergroundSystem {
public:
    unordered_map<int,pair<int,string>> checkInMap;
    unordered_map<string,pair<int,double>> routeMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
       checkInMap[id] = {t,stationName}; 
    }
    
    void checkOut(int id, string stationName, int t) {
       int startTime = checkInMap[id].first; 
       string startStation = checkInMap[id].second;
       checkInMap.erase(id); 
       string route = startStation + "->" + stationName;
       routeMap[route].first += t - startTime;
       routeMap[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" +  endStation;
        return routeMap[route].first / routeMap[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
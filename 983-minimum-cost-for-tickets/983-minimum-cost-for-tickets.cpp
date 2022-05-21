class Solution {
public:
    vector<int> costs;
    unordered_set<int> set;
    unordered_map<int,int> map; 
    int dfs(int day){
        if(map[day])
            return map[day];
        if(day > 365){
            return 0;
        } 
        if(set.find(day) != set.end()){
           return map[day] = min({dfs(day + 1) + costs[0],dfs(day + 7) + costs[1],dfs(day + 30) + costs[2]}); 
        } else {
           return map[day] = dfs(day + 1);
        } 
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        for(int day : days){
            set.insert(day);
        }
        return dfs(1);
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cur = 0,total = 0,start = 0;
        
        for(int i = 0; i < n; i++){
            cur += gas[i] - cost[i];
            total += gas[i] - cost[i];
            
            if(cur < 0){
                cur = 0;
                start = i + 1;
            }
        }
        if(total >= 0)
            return start;
        return -1;
    }
};
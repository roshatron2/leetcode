class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;

        for(int i = 0; i < gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_gas < total_cost){
            return -1;
        }
        int start = 0;
        int total = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                start = i + 1;
            }
        }
        return start;
    }
};

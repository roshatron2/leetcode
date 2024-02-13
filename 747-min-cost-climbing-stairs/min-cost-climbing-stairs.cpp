class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int a = cost[0];
        int b = cost[1];
        int c;
        for(int i = 2; i <= cost.size() - 1; i++){
            c = min(a + cost[i], b + cost[i]);
            a = b;
            b = c;
        }
        return c;
    }
};
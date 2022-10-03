class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int i = 0;
        while(i < colors.size()){
            int curSum = 0;
            int maxEle = 0;
            int j;
            for(j = i; j < colors.size() and colors[i] == colors[j]; j++){
                curSum += neededTime[j];
                maxEle = max(maxEle,neededTime[j]);
            }
            cost += curSum - maxEle;
            i = j;
        }
        return cost;
    }
};
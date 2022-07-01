class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a,vector<int> &b){
            return a[1] > b[1]; 
        });
        int i = 0;
        int maxUnits = 0;
        while(truckSize and i < boxTypes.size()){
            int numberOfBoxes = boxTypes[i][0];
            int numberOfUnits = boxTypes[i][1];
            if(truckSize - numberOfBoxes >= 0){
                truckSize -= numberOfBoxes;
                maxUnits += numberOfBoxes * numberOfUnits;
            } else {
                maxUnits += truckSize * numberOfUnits;
                truckSize = 0;
            }
            i++;
        }
        return maxUnits;
    }
};

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int clockwise = 0,anti = 0;
        if(start > destination)
            swap(start,destination);
        for(int i = start; i < destination; i++){
           clockwise += distance[i]; 
        }    
        int i = destination;
        while(i != start){
           anti += distance[i]; 
           i = (i + 1) % distance.size();
        } 
        return min(clockwise,anti);
    }
};
/*
 0 1  2  3   4  5 6 7
[7 10 1 12 11 14 5 0]
7
2
*/
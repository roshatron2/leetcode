class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int,int> counts;
        for(int i :  hand){
            counts[i]++;
        }
        while(!counts.empty()){
            int cur = counts.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(counts.find(cur + i) == counts.end()){
                    return false;
                }
                counts[cur + i]--;
                if(counts[cur + i] == 0){
                    counts.erase(cur + i);
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> map(60,0);
        for(int i = 0; i < time.size(); i++){
            if(time[i] % 60 == 0){
                if(map[0]){
                    count += map[0];
                }    
                map[0]++;
            }
            else {
                int rem = time[i] % 60;
                if(map[60 - rem])
                    count += map[60 - rem];
                map[rem]++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int mx = 0;
        for(int i = 0; i < seats.size(); i++){
            int rdist = INT_MAX,ldist = INT_MAX,dist;
            if(seats[i] == 0){
                for(int j = i; j < seats.size(); j++){
                    if(seats[j]){
                        rdist = j - i;
                        break;
                    }
                }
                for(int j = i; j >= 0; j--){
                    if(seats[j]){
                        ldist = i - j;
                        break;
                    }
                }
                dist = min(rdist,ldist);
                mx = max(mx,dist);
            }
        }
        return mx;
    }
};
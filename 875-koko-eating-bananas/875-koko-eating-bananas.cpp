class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0,mn = INT_MAX;
        for(int i = 0; i < piles.size(); i++){
            mx = max(mx,piles[i]);
        }
        int l = 1,r = mx,speed;
        while(l <= r){
            speed = (l + r) >> 1;
            int time = 0;
            for(int i = 0; i < piles.size(); i++){
                time += piles[i] / speed;
                time += piles[i] % speed > 0;
            }
            if(time <= h){
                mn = min(mn,speed);
                r = speed - 1;
            }
            else
                l = speed + 1;
        }
        return mn;
    }
};
// l 1 16
// r 30 22
// speed 15 23
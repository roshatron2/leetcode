class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int mx = piles[piles.size()-1];
        int ans = mx;
        int l = 1,r = mx;
        
        while(l <= r){
            int speed = (l + r) >> 1;
            cout<<speed<<endl;
            int t = 0;
            for(int pile : piles){
                t += ceil((double) pile / speed);
                if(t > h){
                    l = speed + 1;
                    break;
                }
            }
            if(t <= h){
                ans = min(ans,speed);
                r = speed - 1;
            }
        }
        return ans;
    }
};
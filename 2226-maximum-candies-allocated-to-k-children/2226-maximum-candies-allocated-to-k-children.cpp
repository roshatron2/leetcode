class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mx = *max_element(candies.begin(),candies.end());
        int l = 1,r = mx;
        int ans = 0;
        while(l <= r){
            int size = (l + r) >> 1;
            long long int piles = 0;
            for(int candy : candies){
               piles += candy / size; 
            }
            if(piles >= k){
                ans = size;        
                l = size + 1;
            } else {
                r = size - 1;
            } 
        }
        return ans;
    }
};
/*
5 8 6
k = 3
l = 5
r = 5
mid = 5
piles = 3
ans = 4
*/
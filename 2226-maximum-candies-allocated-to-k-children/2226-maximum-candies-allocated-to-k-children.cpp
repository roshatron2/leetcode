class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mx = *max_element(candies.begin(),candies.end());
        int l = 1,r = mx;
        int maxCandies = 0;
        while(l <= r){
            int size = l + (r - l) / 2;
            long long int piles = 0;
            for(int candy : candies){
               piles += candy / size; 
            }
            if(piles >= k){
                maxCandies = size;        
                l = size + 1;
            } else {
                r = size - 1;
            } 
        }
        return maxCandies;
    }
};
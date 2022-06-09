class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()),r = INT_MAX;
        int ans;
        while(l <= r){
           int mid = l + (r - l) / 2;
           int time = 0;
           int sum = 0;
           for(int i = 0; i < weights.size(); i++){
              if(sum + weights[i] <= mid){
                  sum += weights[i];
              } else {
                  sum = weights[i];
                  time++;
              }
           }
           if(sum)
               time++;
           if(time <= days){
               ans = mid;
               r = mid - 1;
           } else {
               l = mid + 1;
           }
        }
        return ans;
    }
};
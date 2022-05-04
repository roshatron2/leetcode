class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int curDiff = 0,minDiff = INT_MAX,closestSum;
        for(int i = 0; i < n; i++){
           int l = i + 1,r = n - 1,sum;
           while(l < r){
               sum = nums[i] + nums[l] + nums[r];
               if(sum < target){
                   l++;
               } else if(sum > target){
                   r--;
               } else {
                   l++;
                   r--;
               }
               curDiff = abs(sum - target);
               if(curDiff < minDiff){
                   minDiff = curDiff;
                   closestSum = sum;     
               }
           }
              
        }
        return closestSum;
    }
};
/*
-1 -4 1 2
target - 1
*/
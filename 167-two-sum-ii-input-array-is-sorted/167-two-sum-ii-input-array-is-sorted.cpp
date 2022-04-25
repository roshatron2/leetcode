class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0,r = numbers.size() - 1;
        vector<int> res;
        while(l < r){
           int sum = numbers[l] + numbers[r];
           if(sum < target){
               l++;
           } else if(sum > target){
               r--;
           } else {
              res = {l + 1,r + 1};
              break;
           }
        }
        return res; 
    }
};
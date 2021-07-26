class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mn = INT_MAX,ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                    return sum;
                else if(sum < target){
                    l++;
                } else {
                    r--;
                }
                int dif = abs(sum - target);
                if(mn > dif){
                    mn = dif;
                    ans = sum;
                }
            }
        }        
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> map;
        int target = accumulate(nums.begin(),nums.end(),0) - x;
        int maxi = -1;
        int cur = 0;
        int l = 0,r = 0;
        while(r < nums.size()){
            cur += nums[r];
            while(cur > target and l <= r){
                cur -= nums[l++];
            }
            if(cur == target){
                maxi = max(maxi,r - l + 1);
            }
            r++;
        }
        return maxi != -1 ? nums.size() - maxi : -1;
    }
};
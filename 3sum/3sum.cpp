class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int l,r,n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i == 0 || i >= 0 and nums[i] != nums[i-1]){
                l = i + 1;
                r = n - 1;
                int target = -nums[i];
                while(l < r){
                    int sum = nums[l] + nums[r];
                    if(sum > target){
                        r--;
                    } else if(sum < target){
                        l++;
                    } else {
                        while(l < r and nums[r] == nums[r-1])
                            r--;
                        while(l < r and nums[l] == nums[l+1])
                            l++;
                        vector<int> cur = {nums[i],nums[l],nums[r]};
                        sort(cur.begin(),cur.end());
                        res.push_back(cur);
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
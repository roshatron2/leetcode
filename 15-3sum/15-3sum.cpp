class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < n and nums[l] == nums[l + 1] and l < r) l++;
                    while (r - 1 >= 0 and nums[r] == nums[r - 1] and l < r) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1])
                for (int j = i + 1; j < nums.size(); j++) {
                    int l = j + 1;
                    int r = nums.size() - 1;
                    if(j == i + 1 || nums[j] != nums[j-1]){
                        while (l < r) {
                            long long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                            if (sum == target) {
                                while (l < r && nums[l] == nums[l + 1])
                                    l++;
                                while (l < r && nums[r] == nums[r - 1])
                                    r--;
                                res.push_back({nums[i], nums[j], nums[l], nums[r]});
                                l++;
                                r--;
                            } else if (sum < target) {
                                l++;
                            } else {
                                r--;
                            }
                        }
                    }
            }
        }
        return res;
    }
};
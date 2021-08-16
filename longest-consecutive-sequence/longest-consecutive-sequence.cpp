class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        // sort(nums.begin(),nums.end());
        set<int> set;
        for(auto i : nums){
            set.insert(i);
        }
        nums.assign(set.begin(),set.end());
        int count = 1;
        int mx = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                count++;
            } else {
                count = 1;
            }
            mx = max(mx,count);
        }
        return mx;
    }
};
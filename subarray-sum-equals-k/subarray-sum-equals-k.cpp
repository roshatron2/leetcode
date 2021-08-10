class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map = {{0,1}};
        int sum = 0,count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            count += map[sum - k];
            map[sum]++;
        }
        return count;
    }
};
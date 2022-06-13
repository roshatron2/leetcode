class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = 0;
        long long int cur = 0;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            cur += nums[i];
            if(cur == k){
                len = i + 1;
            }
            if(map.find(cur - k) != map.end()){
                len = max(len,i - map[cur - k]);
            }
            if(map.find(cur) == map.end())
                map[cur] = i;
        }
        return len;
    }
};
class Solution {
public:
    unordered_map<int,int> map;
    int deleteAndEarn(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i : nums){
            map[i]++;
            mx = max(mx,i);
        }
        int prev = 0,cur = map[1];
        int dp = max(prev,cur);
        for(int i = 2; i <= mx; i++){
            dp = max(cur,prev + map[i] * i);
            prev = cur;
            cur = dp;
        }
        return dp;
    }
};

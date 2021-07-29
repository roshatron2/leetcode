class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n,0);
        for(int i = 0; i < n ; i++){
            nums[i] = start + 2 * i;
        }
        int res = 0;
        for(auto i : nums){
            res ^= i;
        }
        return res;
    }
};
class Solution {
public:
    unordered_map<int,int> map;
    int helper(int n){
        if(map[n])
            return map[n];
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        map[n] = helper(n - 2) + helper(n - 1);
        return map[n];
        
    }
    int climbStairs(int n) {
        return helper(n);
    }
};
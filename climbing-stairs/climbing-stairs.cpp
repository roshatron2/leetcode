class Solution {
public:
    unordered_map<int,int> map;
    int dfs(int n){
        if(map[n]){
            return map[n];
        }
        if(n < 0)
            return 0;
        if(n == 0){
            return 1; 
        }
        map[n] += dfs(n - 1) + dfs(n - 2);
        return map[n];
    }
    int climbStairs(int n) {
        return dfs(n);
    }
};
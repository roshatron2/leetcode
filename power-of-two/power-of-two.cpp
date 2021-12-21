class Solution {
public:
    bool dfs(int n){
        if(n == 0)
            return false;
        if(n == 1 || n == 2)
            return true;
        if(n % 2 == 1)
            return false;
        n /= 2;
        return dfs(n);
    }
    bool isPowerOfTwo(int n) {
        return dfs(n);
    }
};
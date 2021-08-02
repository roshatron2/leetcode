class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        for(int i = 1; i <= sqrt(x); i++)
            ans++;
        return ans;
    }
};
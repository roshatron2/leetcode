class Solution {
public:
    int fib(int n) {
        if(n == 0 or n == 1)
            return n;
        vector<int> dp(n + 1,0); 
        int second_last = 0;
        int last = 1;
        int ans;
        for(int i = 2; i <= n; i++){
            ans = last + second_last;
            second_last = last;
            last = ans;
        }
        return ans;
    }
};
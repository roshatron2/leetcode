class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n >= 5){
            if(n % 5 == 0){
                int x = n;
                while(x % 5 == 0 and x >= 5){
                    x /= 5;
                    ans++;
                }
            }
            n--;
        }
        return ans;
    }
};
    
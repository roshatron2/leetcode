class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x){
            int digit = x % 10;
            if(INT_MAX / 10 < rev or INT_MIN / 10 > rev)
                return 0;
            rev = digit + rev * 10; 
            x /= 10;
        }
        return rev;
    }
};
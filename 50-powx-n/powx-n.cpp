class Solution {
public:
    double foo(double x, long long int n){
        if(n == 1){
            return x;
        }
        if(n % 2 == 0){
            double n2 = foo(x, n / 2);
            return n2 * n2;
        }
        double n2 = foo(x, (n - 1) / 2);
        return x * n2  * n2;
    }
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n < 0)
            return foo(1 / x, (long long int)-1 * n);
        return foo(x, n);
    }
};
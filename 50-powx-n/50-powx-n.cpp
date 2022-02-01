class Solution {
public:
    double pow(double x,int n){
        if(n == 1)
            return x;
        if(n == 0)
            return 1;
        double res = pow(x,n/2);
        res *= res;
        return n % 2 ? x * res : res;
    }
    double myPow(double x, int n) {
        double res =  pow(x,abs(n));
        if(n < 0)
            return 1 / res;
        return res;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        double quotient = (double)dividend / divisor;
        if(quotient >= INT_MAX)
            return INT_MAX;
        else if(quotient <= INT_MIN)
            return INT_MIN;
        return quotient;
    }
};
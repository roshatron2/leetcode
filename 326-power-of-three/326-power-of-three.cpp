class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        float power = log(n) / log(3);
        return pow(3,power) == n;
    }
};
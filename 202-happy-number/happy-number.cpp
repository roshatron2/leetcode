class Solution {
public:
    unordered_set<int> set;
    bool foo(int n){
        if(n == 1){
            return true;
        }
        if(set.find(n) != set.end()){
            return false;
        }
        set.insert(n);
        int sum = 0;
        while(n){
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return foo(sum);
    }
    bool isHappy(int n) {
        return foo(n);
    }
};
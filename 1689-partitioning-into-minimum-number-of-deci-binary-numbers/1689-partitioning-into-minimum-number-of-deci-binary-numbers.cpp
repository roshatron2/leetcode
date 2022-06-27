class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for(char i : n){
            int digit = i - '0'; 
            maxDigit = max(maxDigit,digit);
        }    
        return maxDigit;
    }
};
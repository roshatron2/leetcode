class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0]++;
        int carry = digits[0] / 10;
        digits[0] = digits[0] % 10;
        for(int i = 1; i < digits.size(); i++){
            if(carry){
                digits[i] += 1;
                carry = digits[i] / 10;
            }
            digits[i] = digits[i] % 10;
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

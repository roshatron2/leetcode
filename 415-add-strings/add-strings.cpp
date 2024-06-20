class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;    
        int j = num2.size() - 1;
        int carry = 0;
        string res;
        while(i >= 0 or j >= 0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int digit = x + y + carry;
            carry = digit / 10;
            digit = digit % 10;
            res += to_string(digit);
            i--;
            j--;
        }
        if(carry){
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
0 1 2 
1 1
1 2 3
1 3 4

i = -1
j = 0
x = 0
y = 1
d = 1
c = 0

*/

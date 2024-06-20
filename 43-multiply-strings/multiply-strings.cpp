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
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size(); 
        vector<string> nums;
        string res = "0";
        int zeroes = 0;
        for(int i = m - 1; i >= 0; i--){
            int x = num1[i] - '0';        
            int carry = 0;
            string num;
            for(int k = 0; k < zeroes; k++){
                num += "0";
            }
            for(int j = n - 1; j >= 0; j--){
                int y = num2[j] - '0';
                int prod = x * y + carry;
                carry = prod / 10;
                prod = prod % 10;
                num += to_string(prod);
            }
            if(carry){
                num += to_string(carry);
            }
            reverse(num.begin(), num.end());
            res = addStrings(res, num);
            zeroes++;
        }
        return res[0] == '0' ? "0" : res;
    }
};
/*
0 1
9
9 9

i = 0
j = 0 

x = 9
y = 9
zeroes = 0
prod =  9
carry = 8
num = 198
*/

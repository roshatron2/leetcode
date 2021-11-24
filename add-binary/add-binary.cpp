class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1,j = b.size() - 1,carry = 0,x,y,digit,sum;
        string ans;
        while(i >= 0 or j >= 0){
            i >= 0 ?  x = a[i] - '0' : x = 0;
            j >= 0 ?  y = b[j] - '0' : y = 0;
            sum = carry + x + y;
            digit = sum % 2;
            ans += '0' + digit;
            carry = sum / 2;
            i--;
            j--;
        }
        if(carry)
            ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
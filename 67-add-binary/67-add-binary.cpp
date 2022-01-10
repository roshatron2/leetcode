class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1,carry = 0;
        string res;
        while(i >= 0 or j >= 0){
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            int sum = (x + y + carry);
            int digit = sum % 2;
            carry = sum / 2;
            res += digit + '0';
            i--;
            j--;
        }
        if(carry){
            res += '1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
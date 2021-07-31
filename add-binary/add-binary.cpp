class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1,n = b.size() - 1,carry = 0;
        string res;
        while(m >= 0 or n >= 0){
            int x = m >= 0 ? a[m] - '0' : 0;
            int y = n >= 0 ? b[n] - '0' : 0;
            int sum = x + y + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            m--;
            n--;
        }
        if(carry){
            res.push_back('1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
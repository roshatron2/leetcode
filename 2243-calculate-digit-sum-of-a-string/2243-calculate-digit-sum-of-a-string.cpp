class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k)
            return s;
        string digits;
        for(int i = 0; i < s.size(); i += k){
            string window = s.substr(i,k);
            int sum = 0;
            for(char i : window){
               sum += i - '0'; 
            }
            digits += to_string(sum);
        }
        return digitSum(digits,k);
    }
};
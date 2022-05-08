class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k){
            return s;
        }
        string digits;
        for(int i = 0; i < s.size(); i += k){
            string cur = s.substr(i,k);
            int sum = 0;
            for(char i : cur){
               sum += i - '0'; 
            }
            digits += to_string(sum);
        }
        return digitSum(digits,k);
    }
};
/*
i = 0 3

111 112 222 23
34

*/
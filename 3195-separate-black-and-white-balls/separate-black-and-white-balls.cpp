class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0; 

        int zeroes = 0; 
        for(int i = s.size(); i >= 0; i--){
            if(s[i] == '0')
                zeroes++;
            if(s[i] == '1')
                res += zeroes;
        }
        return res;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        long int num = 0;
        int sign = 1;
        bool sign_found = false;
        bool num_found = false;
        int i = 0;
        while(s[i] == ' ')
                i++;
        for(; i < s.size(); i++){
            if((s[i] >= 'a' and s[i] <= 'z') or ((s[i] == '-' || s[i] == '+') and sign_found))
                break;
            if(num_found and (s[i] == '-' or s[i] == '+'))
                return num;
            if(s[i] == '-'){
                sign = -1;
                sign_found = true;
            }
            if(s[i] == '+')
                sign_found = true;
            if((s[i] == '+' or s[i] == '-') and num_found)
                return sign * num;
            if(s[i] == '.')
                    return sign * num;
            if(s[i] == ' ')
                return sign * num;
            if(isdigit(s[i])){
                num_found = true;
                num = num * 10 + (s[i] - '0');
                if(num * sign >= INT_MAX)
                    return INT_MAX;
                if(num * sign <= INT_MIN)
                    return INT_MIN;
            }
        }
        return sign * num;
    }
};
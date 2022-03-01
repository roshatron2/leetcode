class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string ans;
        if(num < 0 and den > 0 or num > 0 and den < 0){
            ans += "-";
        }
        num = abs(num);
        den = abs(den);
        long quotient = (long)num /den;
        long rem = num % den;
        ans += to_string(quotient);
        if(rem == 0)
            return ans;
        ans += ".";
        unordered_map<long,int> map;
        while(rem){
            if(map[rem]){
                ans.insert(map[rem],"(");
                ans += ")";
                break;
            }
            map[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem = rem % den;
        }
        return ans;
    }
};
    
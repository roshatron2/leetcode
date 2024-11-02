class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string res;
        if(n < 3)
            return s;
        res += s[0];
        res += s[1];
        for(int i = 2; i < n; i++){
            if(s[i - 1] != s[i] or s[i - 2] != s[i]){
                res += s[i];
            }
        }      
        return res;
    }
};
class Solution {
public:
    bool isPal(string s){
        int l = 0,r = s.size() - 1;
        while(l <= r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.empty()){
            return 0;
        }    
        int l = 0,r = s.size() - 1;
        if(isPal(s)){
            return 1;
        }
        return 2;
    }
};
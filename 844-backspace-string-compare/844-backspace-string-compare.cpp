class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1,j = t.size() - 1;
        int skipS = 0,skipT = 0;
        while(i >= 0 or j >= 0){
            while(i >= 0 and (s[i] == '#' or skipS)){
                s[i--] == '#' ? skipS++ : skipS--;
            }
            while(j >= 0 and (t[j] == '#' or skipT)){
                t[j--] == '#' ? skipT++ : skipT--;
            }
            if(i == -1 or j == -1)
                return i == j;
            if(s[i--] != t[j--]){
                return false;
            }
        }
        return true;
    }
};
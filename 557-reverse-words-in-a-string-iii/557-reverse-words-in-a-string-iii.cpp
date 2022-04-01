class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        int i = 0,j = 0;
        while(s[j] == ' ') j++;
        i = j;
        while(i < s.size()){
            if(s[i] == ' '){
                reverse(s.begin() + j,s.begin() + i);
                while(s[i] == ' ') i++;
                j = i;
            }
            i++;
        }
        s.pop_back();
        return s;
    }
};
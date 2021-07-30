class Solution {
public:
    string reverseWords(string s) {
        int start = 0,end;
        int j = 0,i = 0;
        while(s[i] == ' ')
            i++;
        for(; i < s.size(); i++){
            if(s[i] == ' ' and s[i] == s[i-1]) continue;
            s[j++] = s[i];
        }
        s[s.size() - 1] == ' ' ? s.erase(j - 1) : s.erase(j);
        for(i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                end = i;
                reverse(s.begin() + start,s.begin() + end);
                start = i + 1;
            }
        }
        reverse(s.begin() + start,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};
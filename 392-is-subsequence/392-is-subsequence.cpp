class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j = 0;
        while(i < s.size() and j < t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == s.size();
    }
};

// a : 1 b : 1 c : 1
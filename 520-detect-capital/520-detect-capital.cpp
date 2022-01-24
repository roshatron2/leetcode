class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1)
            return true;
        for(int i = 0; i < n; i++){
            if(isupper(word[i]) and islower(word[0]))
                return false;
        }
        int i = 0;
        while(i < n){
            if(islower(word[i]))
                break;
            i++;
        }
        if(i == n)
            return true;
        i = 1;
        if(isupper(word[0]))
            while(i < n){
             if(isupper(word[i]))
                 return false;
             i++;
            }
        return true;
    }
};
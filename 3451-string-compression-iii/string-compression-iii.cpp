class Solution {
public:
    string compressedString(string word) {
        word += " ";
        char cur = word[0];
        int count = 1;
        string res;
        for(int i = 1; i < word.size(); i++){
            if(word[i] == cur and count < 9) {
                count++;
            } else {
                res += to_string(count) + cur;
                cur = word[i];
                count = 1;
            }
        }    

        return res;
    }
};
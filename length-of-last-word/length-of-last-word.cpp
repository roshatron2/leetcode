class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int ans = 0;
        while(ss >> word) ans = word.size();
        return ans;
        
    }
};
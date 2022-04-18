class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> set;
        for(char i : s){
            if(set.find(i) != set.end()){
                set.erase(i);
            }
            else {
                set.insert(i);
            }
        }
        return set.size() <= 1;
    }
};
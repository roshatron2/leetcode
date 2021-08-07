class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> map;
       int len = 1; 
       int j = 0;
       if(s == "")
           return 0;
       for(int i = 0; i < s.size(); i++){
          if(map[s[i]]){
              j = max(map[s[i]],j);
          }
           len = max(len,i - j + 1);
           map[s[i]] = i + 1;
       }
       return len; 
    }
};
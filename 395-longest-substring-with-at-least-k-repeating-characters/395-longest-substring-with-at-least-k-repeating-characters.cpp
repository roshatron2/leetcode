class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty())   
            return 0;
        unordered_map<char,int> map;
        for(char i : s){
            map[i]++;
        }
        int mid = 0;
        while(mid < s.size() and map[s[mid]] >= k){
            mid++;
        }
        
        if(mid == s.size())
            return s.size();
        int midNext = mid + 1;
        while(midNext < s.size() and map[s[midNext]] < k)
            midNext++;
        int left = longestSubstring(s.substr(0,mid),k);
        int right = longestSubstring(s.substr(midNext),k);
        return max(left,right);
    }
};
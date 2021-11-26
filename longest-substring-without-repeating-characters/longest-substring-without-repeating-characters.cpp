class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int l = 0,r = 0,ans = 0;
        while(r < s.size()){
            char right = s[r];
            map[right]++;
            
            while(map[right] > 1){
                char left = s[l];
                map[left]--;
                l++;
            }
            ans = max(ans,r - l + 1);
            r++;
        }
        return ans;
    }
};